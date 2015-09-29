#ifndef IMEVOLVE_INCLUDE_SELETORNATURAL_H
#define IMEVOLVE_INCLUDE_SELETORNATURAL_H
#include "individuo.h"

using Populacao = std::vector<Individuo>;

class SeletorNatural{
private:
  Populacao &populacao;
public:
  SeletorNatural(Populacao& ipopulacao):populacao(ipopulacao){}
  virtual void selecionarParceiros(Individuo& pai, Individuo& mae);

};

#endif
