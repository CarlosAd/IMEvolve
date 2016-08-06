#include "geracao.h"
#include <iostream>
#include <algorithm>

Geracao::Geracao() : valorDeAdaptacaoTotal(0), populacao(0), populacaoAuxiliar(0) {
}

void Geracao::gerarPopulacao() {
  populacaoAuxiliar.resize(tamanhoPopulacao - elitismo, Individuo(tamanhoCromossomo));

  for (int indice = 0; indice < tamanhoPopulacao; indice++) {
    populacao.push_back(Individuo(tamanhoCromossomo));
  }
}

double Geracao::calcularAdaptacao(int meu_rank, const Individuo& idv) {
  return (*funcaoObjetivo)(idv);
}

void Geracao::calcularAdaptacaoTotal() {
  valorDeAdaptacaoTotal = 0;
  for (int indice = 0; indice < tamanhoPopulacao; indice++) {
    valorDeAdaptacaoTotal += populacao[indice].adaptacao();
  }
}

void Geracao::evoluir() {
  calcularAdaptacaoTotal();
  sort (populacao.rbegin(), populacao.rend());
  int numeroDeFilhos = tamanhoPopulacao - elitismo;
  Individuo pai, mae;

  int indice;
  for (indice = 0; indice < numeroDeFilhos; indice++) {
    seletorNatural->selecionarParceiros(populacao, valorDeAdaptacaoTotal);

    pai = populacao[seletorNatural->retornaPai()];
    mae = populacao[seletorNatural->retornaMae()];

    populacaoAuxiliar[indice] = funcaoReproducao->reproducao (pai, mae);
    funcaoMutacao->mutacao (populacaoAuxiliar[indice]);
  }

  std::swap_ranges (populacaoAuxiliar.begin(), populacaoAuxiliar.end(), populacao.begin() + elitismo);

}

Individuo& Geracao::pegarMaisAdaptado(){
  int indice = 0;
  for(int i = 1; i < populacao.size(); i++){
    if(populacao[i].adaptacao() > populacao[indice].adaptacao()){
      indice = i;
    }
  return populacao[indice];
  }
}

void Geracao::preProcessamento(){}

void Geracao::posProcessamento(){}

bool Geracao::parar(){
  return false;
}

void Geracao::atribuirValoresAdaptacao(int indicePrimeiro, int tamanho, double *valoresAdaptacao) {
  int i;
  for(i = 0; i < tamanho; i++) 
  {
    populacao[indicePrimeiro + i].atribuirValorDeAdaptacao(valoresAdaptacao[i]);
  }
}

int Geracao::getTamanhoPopulacao() {
  return tamanhoPopulacao;
}

int Geracao::getTamanhoCromossomo() {
  return tamanhoCromossomo;
}

const Populacao& Geracao::getPopulacao() {
  return populacao;
}
