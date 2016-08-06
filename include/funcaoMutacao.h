#ifndef IMEVOLVE_INCLUDE_FUNCAO_MUTACAO_H
#define IMEVOLVE_INCLUDE_FUNCAO_MUTACAO_H

#include "individuo.h"

class FuncaoMutacao{
protected:
  double taxaMutacao;
public:
  FuncaoMutacao(double TM):taxaMutacao(TM){}
  virtual void mutacao(Individuo& mutante);

};



#endif
