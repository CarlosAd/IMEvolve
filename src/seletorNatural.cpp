#include "seletorNatural.h"
#include <random>

void SeletorNatural::selecionarParceiros(Populacao& populacao, double valorAdaptacaoPopulacao) {
  std::default_random_engine gerador;
  double escolha;
  int i, tamanho = populacao.size();
    
  std::uniform_real_distribution<double> rd(0.0,valorAdaptacaoPopulacao);

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
