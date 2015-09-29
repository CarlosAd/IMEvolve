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
  FuncaoReproducao &fucaoReproducao;

  Populacao populacao, populacaoAuxiliar;
  unsigned int tamanhoPopulacao, elitismo;
    

public:
  Geracao(FuncaoObjetivo &ifuncaoObjetivo, 
          SeletorNatural &iseletorNatural, 
          FuncaoMutacao &ifuncaoMutacao,
          FuncaoReproducao &ifucaoReproducao,
          FuncaoEvoluir &ifuncaoEvoluir,
          const unsigned int itamanhoPopulacao, 
          const unsigned int ielitismo): 
          funcaoObjetivo(ifuncaoObjetivo),
          seletorNatural(iseletorNatural),
          funcaoMutacao(ifuncaoMutacao),
          funcaoReproducao(ifucaoReproducao),
          tamanhoPopulacao(itamanhoPopulacao),
          elitismo(ielitismo){}

  virtual void evoluir();

  Individuo& pegarMaisAdaptado();
};




#endif
