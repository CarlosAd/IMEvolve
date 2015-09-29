#ifndef IMEVOLVE_INCLUDE_INDIVIDUO_H
#define IMEVOLVE_INCLUDE_INDIVIDUO_H

#include <vector>

using cromo = std::vector< unsigned char >;

class Individuo {
//private:
public:
  cromo cromossomos_;
  double valorDeAdaptacao_;
  
public:
  Individuo (const cromo &novosCromossomos);
  Individuo (const int &quantidadeDeCromossomos);
  unsigned char operator[] (const int &posicao) const;
  double adaptacao () const;
  int tamanho () const;
  void atribuirValorDeAdaptacao (const double novoValorDeAdaptacao);
};

#endif
