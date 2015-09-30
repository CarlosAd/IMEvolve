#ifndef IMEVOLVE_INCLUDE_SELETORNATURAL_H
#define IMEVOLVE_INCLUDE_SELETORNATURAL_H
#include "individuo.h"

using Populacao = std::vector<Individuo>;

class SeletorNatural{
protected:
  unsigned int pai, mae;
public:
  virtual void selecionarParceiros(Populacao& populacao);
  unsigned int retornaPai();
  unsigned int retornaMae();

};

#endif
