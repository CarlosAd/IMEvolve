#include "funcaoMutacao.h"
#include <random>

void FuncaoMutacao::mutacao(Individuo& mutante){
  std::random_device rd;
  int i;
  double j;
  j = (rd()%100001)/100000.0;
  
  if(j <= taxaMutacao)
  {
    i = rd()%mutante.cromossomos_.size();
    mutante.cromossomos_[i] = rd()%256;
  }
}
