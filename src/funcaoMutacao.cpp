#include "funcaoMutacao.h"
#include <random>

void FuncaoMutacao::mutacao(Individuo& mutante){
  std::random_device rd1;
  std::default_random_engine gerador;
  std::uniform_real_distribution<double> rd2(0.0,1.0);
  int i;
  double j;
  j = rd2(gerador);
  
  if(j <= taxaMutacao)
  {
    i = rd1()%mutante.cromossomos_.size();
    mutante.cromossomos_[i] = rd1()%256;
  }
}
