#ifndef MINHA_GERACAO_H
#define MINHA_GERACAO_H

#include "geracao.h"

class MinhaFuncaoObjetivo : public FuncaoObjetivo {
  double operator() (const Individuo& avaliado);
};

class MinhaGeracao : public Geracao {
public:
  MinhaGeracao();
  bool parar();
  void preProcessamento();
  void posProcessamento();
};

#endif
