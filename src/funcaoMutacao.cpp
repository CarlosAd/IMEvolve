#include "funcaoMutacao.h"
#include <random>

void FuncaoMutacao::mutacao(Individuo& mutante){
  std::uniform_int_distribution<int> valor(0, 255);
  std::uniform_int_distribution<int> posicao(0, mutante.cromossomos_.size() - 1);
  std::uniform_real_distribution<double> probabilidade(0.0, 1.0);
  std::random_device rd;

  int i;
  double j;
  j = probabilidade(rd);
  
  if(j <= taxaMutacao)
  {
    i = posicao(rd);
    mutante.cromossomos_[i] = valor(rd);
  }
}
