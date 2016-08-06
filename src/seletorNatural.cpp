#include "seletorNatural.h"
#include <random>

void SeletorNatural::selecionarParceiros(Populacao& populacao, double valorAdaptacaoPopulacao) {
  std::random_device rd;
  double escolha;
  int i, tamanho = populacao.size();
    
  std::uniform_real_distribution<double> double_dist(0.0,valorAdaptacaoPopulacao);

  escolha = double_dist(rd);

  for(i = 0; i < tamanho; i++)
  {
    escolha -= populacao[i].adaptacao();
    
    if(escolha <= 0)
    {
      pai = mae = i;
      i = tamanho;
    }
    
  } 

  do{
    escolha = double_dist(rd);

    for(i = 0; i < tamanho; i++)
    {
      escolha -= populacao[i].adaptacao();
      
      if(escolha <= 0)
      {
        mae = i;
        i = tamanho;
      }
      
    } 
  }while(pai == mae);
}

unsigned int SeletorNatural::retornaPai(){
  return pai;
}

unsigned int SeletorNatural::retornaMae(){
  return mae;
}
