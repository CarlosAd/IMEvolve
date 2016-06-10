#ifndef IMEVOLVE_INCLUDE_FUNCAO_OBJETIVO_H
#define IMEVOLVE_INCLUDE_FUNCAO_OBJETIVO_H

#include "individuo.h"

class FuncaoObjetivo {
public:
  virtual double operator()(const Individuo& avaliado) = 0;
};

#endif
