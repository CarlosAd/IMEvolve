#include "seletorNatural.h"
#include <random>

void SeletorNatural::selecionarParceiros(Populacao& populacao){
  std::default_random_engine gerador;
  double total = 0, escolha;
  int i, tamanho = populacao.size();
    
  for(i = 0; i < tamanho; i++)
  {
    total += populacao[i].adaptacao();
  }
  std::uniform_real_distribution<double> rd(0.0,total);

  escolha = rd(gerador);

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
    escolha = rd(gerador);

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
