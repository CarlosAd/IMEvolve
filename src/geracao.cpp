#include "geracao.h"
#include <algorithm>

Geracao::Geracao(FuncaoObjetivo &ifuncaoObjetivo,
                 SeletorNatural &iseletorNatural,
                 FuncaoMutacao &ifuncaoMutacao,
                 FuncaoReproducao &ifuncaoReproducao) :
                 funcaoObjetivo (ifuncaoObjetivo),
                 seletorNatural (iseletorNatural),
                 funcaoMutacao (ifuncaoMutacao),
                 funcaoReproducao (ifuncaoReproducao),
                 valorDeAdaptacaoTotal(0) {
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

  calcularAdaptacaoPopulacao();
}

void Geracao::calcularAdaptacaoPopulacao() {
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
  calcularAdaptacaoPopulacao();
  calcularAdaptacaoTotal();

  for(int indice = 0; indice < elitismo; indice++){
    funcaoMutacao.mutacao(populacao[indice]);
  }

  int numeroDeFilhos = tamanhoPopulacao - elitismo;
  Individuo pai, mae;

  for (indice = 0; indice < numeroDeFilhos; indice++) {
    seletorNatural.selecionarParceiros(populacao, valorDeAdaptacaoTotal);

    pai = populacao[seletorNatural.retornaPai()];
    mae = populacao[seletorNatural.retornaMae()];

    populacaoAuxiliar[indice] = funcaoReproducao.reproducao (pai, mae);
    funcaoMutacao.mutacao (populacaoAuxiliar[indice]);
  }

  std::swap_ranges (populacaoAuxiliar.begin(), populacaoAuxiliar.end(), populacao.begin() + elitismo);
}
