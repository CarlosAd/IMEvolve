#include "funcaoReproducao.h"
#include "individuo.h"
#include <random>

Individuo FuncaoReproducao::reproducao(Individuo& pai, Individuo& mae){
  std::uniform_int_distribution<int> posicao(1, pai.cromossomos_.size() - 1);
  std::random_device rd;
  int i = posicao(rd);
  Individuo filho(0);
    
  filho.cromossomos_.insert(filho.cromossomos_.begin(),
                            pai.cromossomos_.begin(),
                            pai.cromossomos_.begin() + i);

  filho.cromossomos_.insert(filho.cromossomos_.begin() + i,
                            mae.cromossomos_.begin() + i,
                            mae.cromossomos_.end());

  return filho;
}
