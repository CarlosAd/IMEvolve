#ifndef IMEVOLVE_INCLUDE_FUNCAO_REPRODUCAO_H
#define IMEVOLVE_INCLUDE_FUNCAO_REPRODUCAO_H

#include "individuo.h"

class FuncaoReproducao{
public:
  virtual Individuo reproducao(Individuo& pai, Individuo& mae);

};


#endif
