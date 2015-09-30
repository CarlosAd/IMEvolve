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
    

public:
  Geracao(FuncaoObjetivo &ifuncaoObjetivo,
          SeletorNatural &iseletorNatural,
          FuncaoMutacao &ifuncaoMutacao,
          FuncaoReproducao &ifuncaoReproducao);

  void gerarPopulacao(const unsigned int& itamanhoCromossomo,
                const unsigned int& itamanhoPopulacao,
                const unsigned int& ielitismo);

  virtual void evoluir();

  Individuo& pegarMaisAdaptado();
};




#endif
