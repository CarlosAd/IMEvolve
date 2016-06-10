#include "geracao.h"
#include <iostream>

class MinhaFuncaoObjetivo : public FuncaoObjetivo {
  double operator() (const Individuo& avaliado) {
    double sum = 0;
    for (int i = 0; i < avaliado.tamanho(); i++) {
      for (int j = i; j < avaliado.tamanho(); j++) {
        sum += ((avaliado[i] - avaliado[j]) * (avaliado[i] - avaliado[j]));
      }
    }
    return sum;
  }
};

int main() {
  MinhaFuncaoObjetivo mfo; //Implementada pelo usuário
  SeletorNatural msn;      //Roleta Russa
  FuncaoReproducao mfr;    //Reprodução Um-Ponto
  FuncaoMutacao mfm(0.8);  //Taxa de mutação de 8%

  Geracao minhaGeracao (mfo, msn, mfm, mfr);
  //Tamanho dos cromossomos: 10; 
  //Tamanho da população: 100;
  //Número de elementos da elite: 1.
  minhaGeracao.gerarPopulacao (10, 100, 1);
  std::cout << "k\n";

  minhaGeracao.calcularAdaptacaoPopulacao();

  std::cout << 0 << " - " << minhaGeracao.pegarMaisAdaptado().valorDeAdaptacao_ << "\n";

  int epoca = 0;
  while (minhaGeracao.pegarMaisAdaptado().valorDeAdaptacao_ <= 100000000){
    minhaGeracao.evoluir();

    std::cout << (++epoca) << " - ";
    minhaGeracao.pegarMaisAdaptado().imprimir();
  }
}
