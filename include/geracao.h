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
  FuncaoObjetivo &funcaoObjetivo;
  SeletorNatural &seletorNatural; 
  FuncaoMutacao &funcaoMutacao;
  FuncaoReproducao &funcaoReproducao;

  Populacao populacao, populacaoAuxiliar;
  unsigned int tamanhoPopulacao, elitismo;
  double valorDeAdaptacaoTotal;
    

public:
  Geracao(FuncaoObjetivo &ifuncaoObjetivo,
          SeletorNatural &iseletorNatural,
          FuncaoMutacao &ifuncaoMutacao,
          FuncaoReproducao &ifuncaoReproducao);

  void gerarPopulacao(unsigned int itamanhoCromossomo,
                      unsigned int itamanhoPopulacao,
                      unsigned int ielitismo);

  void calcularAdaptacaoPopulacao();
  virtual void evoluir();

  Individuo& pegarMaisAdaptado();
};




#endif
