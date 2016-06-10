#include "individuo.h"
#include <algorithm>
#include <random>
#include <iostream>

Individuo::Individuo () {
}

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
  return valorDeAdaptacao_;
}

int Individuo::tamanho () const {
  return cromossomos_.size();
}

void Individuo::atribuirValorDeAdaptacao(const double novoValorDeAdaptacao){
  valorDeAdaptacao_ = novoValorDeAdaptacao;
}

bool Individuo::operator< (const Individuo& individuoADireita) const{
  return (valorDeAdaptacao_ < individuoADireita.adaptacao());
}

void Individuo::operator= (const Individuo& individuoADireita) {
  cromossomos_.assign(individuoADireita.cromossomos_.begin(), individuoADireita.cromossomos_.end());
  valorDeAdaptacao_ = individuoADireita.adaptacao();
}

void Individuo::imprimir () const{
  std::cout << valorDeAdaptacao_ << "\t";
  for (int i = 0; i < cromossomos_.size(); i++) {
    std::cout << static_cast<int>(cromossomos_[i]) << " ";
  }
  std::cout << std::endl;
}
