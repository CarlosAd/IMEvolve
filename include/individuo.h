#ifndef IMEVOLVE_INCLUDE_INDIVIDUO_H
#define IMEVOLVE_INCLUDE_INDIVIDUO_H

#include <vector>

using cromo = std::vector< unsigned char >;

class Individuo {
  cromo cromossomos_;
  double valorDeAdaptacao_;
  
public:
  Individuo (const cromo &novosCromossomos);
  Individuo (const int &quantidadeDeCromossomos);
  void reproducao (Individuo *par);
  bool mutacao (const double &taxaDeMutacao);
  unsigned char operator[] (const int &posicao) const;
  double adaptacao () const;
  int tamanho () const;
  void atribuirValorDeAdaptacao (const double &novoValorDeAdaptacao);
};

#endif
