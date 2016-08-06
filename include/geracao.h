#ifndef IMEVOLVE_INCLUDE_GERACAO_H
#define IMEVOLVE_INCLUDE_GERACAO_H

#include <vector>
#include "individuo.h"
#include "funcaoObjetivo.h"
#include "seletorNatural.h"
#include "funcaoReproducao.h"
#include "funcaoMutacao.h"

using Populacao = std::vector<Individuo>;

class Geracao{
protected:
  FuncaoObjetivo *funcaoObjetivo;
  SeletorNatural *seletorNatural; 
  FuncaoMutacao *funcaoMutacao;
  FuncaoReproducao *funcaoReproducao;

  Populacao populacao, populacaoAuxiliar;
  unsigned int tamanhoCromossomo, tamanhoPopulacao, elitismo;
  double valorDeAdaptacaoTotal;

public:
  Geracao();

  virtual void gerarPopulacao();

  double calcularAdaptacao(int meu_rank, const Individuo& idv);
  void calcularAdaptacaoTotal();
  virtual void evoluir();

  virtual void preProcessamento();
  virtual void posProcessamento();
  virtual bool parar();
  Individuo& pegarMaisAdaptado();

  void atribuirValoresAdaptacao(int, int, double*);
  int getTamanhoPopulacao();
  int getTamanhoCromossomo();
  const Populacao& getPopulacao();
};




#endif
