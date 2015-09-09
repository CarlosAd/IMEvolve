#include "../include/individuo.h"
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

void Individuo::reproducao (Individuo *par) {
  std::random_device rd;

  int pontoDeCorte = rd() % tamanho();

  for (int index = pontoDeCorte; index < tamanho(); index++) {
    std::swap (cromossomos_[index], par->cromossomos_[index]);
  }
}

unsigned char Individuo::operator[] (const int &posicao) const{
  return cromossomos_[posicao];
}

int Individuo::tamanho () const {
  return cromossomos_.size();
}
