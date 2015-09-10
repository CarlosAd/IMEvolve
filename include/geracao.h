#ifndef IMEVOLVE_INCLUDE_GERACAO_H
#define IMEVOLVE_INCLUDE_GERACAO_H

#include <vector>

using Populacao = vector<Individuo>

class Geracao{
protected:
  FuncaoObjetivo &funcaoObjetivo;
  SeletorNatural &seletorNatural; 
  Populacao populacao, populacaoAuxiliar;
  unsigned int elitismo, tamanhoPopulacao;
  double taxaMutacao;
  virtual void mutacao(int indice);
  virtual void reproducao(int pai, int mae);
    

public:
  Geracao(const FuncaoObjetivo &ifuncaoObjetivo, 
          const SeletorNatural &iseletorNatural, 
          const int itamanhoPopulacao, 
          const int ielitismo, 
          const double itaxaMutacao):
           funcaoObjetivo(ifuncaoObjetivo),
           seletorNatural(iseletorNatural),
           tamanhoPopulacao(itamanhoPopulacao),
           elitismo(ielitismo),
           taxaMutacao(itaxaMutacao);

  virtual void evoluir();

  Individuo& pegarMaisAdaptado();
};




#endif
