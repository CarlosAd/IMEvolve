#include "individuo.h"
#include <algorithm>
#include <random>

Individuo::Individuo (const cromo &novosCromossomos) : cromossomos_ (novosCromossomos), valorDeAdaptacao_ (0) {
}

Individuo::Individuo (const int &quantidadeDeCromossomos) : valorDeAdaptacao_ (0) {
  std::random_device rd;

  for (int index = 0; index < quantidadeDeCromossomos; index++) {
    cromossomos_.push_back (rd() % 256);
  }
}

unsigned char Individuo::operator[] (const int &posicao) const{
  return cromossomos_[posicao];
}

double Individuo::adaptacao() const{
  return valorAdaptacao_;
}

int Individuo::tamanho () const {
  return cromossomos_.size();
}

void atribuirValorDeAdaptacao(const double novoValorDeAdaptacao){
  valorDeAdaptacao = novoValorDeAdaptacao;
}
