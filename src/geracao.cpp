#include "geracao.h"
#include <iostream>
#include <algorithm>

Geracao::Geracao(FuncaoObjetivo &ifuncaoObjetivo,
                 SeletorNatural &iseletorNatural,
                 FuncaoMutacao &ifuncaoMutacao,
                 FuncaoReproducao &ifuncaoReproducao) :
                 funcaoObjetivo (ifuncaoObjetivo),
                 seletorNatural (iseletorNatural),
                 funcaoMutacao (ifuncaoMutacao),
                 funcaoReproducao (ifuncaoReproducao), valorDeAdaptacaoTotal(0),
                 populacao(0), populacaoAuxiliar(0) {
  std::cout << "SIZE: " << populacao.size() << std::endl;
}

void Geracao::gerarPopulacao(unsigned int itamanhoCromossomo,
                             unsigned int itamanhoPopulacao,
                             unsigned int ielitismo) {
  tamanhoPopulacao = itamanhoPopulacao;
  elitismo = ielitismo;
  populacaoAuxiliar.resize(tamanhoPopulacao - elitismo, Individuo(itamanhoCromossomo));

  for (int indice = 0; indice < itamanhoPopulacao; indice++) {
    populacao.push_back(Individuo(itamanhoCromossomo));
  }
}

void Geracao::calcularAdaptacaoPopulacao() {
//paralelizar esse método
  double valorDeAdaptacao;
  for (int indice = 0; indice < tamanhoPopulacao; indice++) {
    valorDeAdaptacao = funcaoObjetivo(populacao[indice]);
    populacao[indice].atribuirValorDeAdaptacao(valorDeAdaptacao);
  }
  sort (populacao.rbegin(), populacao.rend());
}

void Geracao::calcularAdaptacaoTotal() {
  valorDeAdaptacaoTotal = 0;
  for (int indice = 0; indice < tamanhoPopulacao; indice++) {
    valorDeAdaptacaoTotal += populacao[indice].adaptacao();
  }
}

void Geracao::evoluir() {

  calcularAdaptacaoTotal();
  int numeroDeFilhos = tamanhoPopulacao - elitismo;
  Individuo pai, mae;

  int indice;
  for (indice = 0; indice < numeroDeFilhos; indice++) {
    seletorNatural.selecionarParceiros(populacao, valorDeAdaptacaoTotal);

    pai = populacao[seletorNatural.retornaPai()];
    mae = populacao[seletorNatural.retornaMae()];

    populacaoAuxiliar[indice] = funcaoReproducao.reproducao (pai, mae);
    funcaoMutacao.mutacao (populacaoAuxiliar[indice]);
  }

  std::swap_ranges (populacaoAuxiliar.begin(), populacaoAuxiliar.end(), populacao.begin() + elitismo);

  calcularAdaptacaoPopulacao();
}
