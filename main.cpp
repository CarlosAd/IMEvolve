#include "geracao.h"
#include <iostream>

class MinhaFuncaoObjetivo : public FuncaoObjetivo {
  double operator() (const Individuo& avaliado);
};

double MinhaFuncaoObjetivo::operator() (const Individuo& avaliado) {
  double res = 0.0;
  for (int i = 0; i < avaliado.tamanho(); i++) {
    res += avaliado[i];
  }

  return res;
}

int main() {
  MinhaFuncaoObjetivo mfo;
  SeletorNatural msn;
  FuncaoReproducao mfr;
  FuncaoMutacao mfm (0.3);

  Geracao minhaGeracao (mfo, msn, mfm, mfr);
  minhaGeracao.gerarPopulacao (10, 20, 3);


  minhaGeracao.calcularAdaptacaoPopulacao();
  std::cout << 0 << " - " << minhaGeracao.pegarMaisAdaptado().valorDeAdaptacao_ << "\n";
  for(int i = 0; i < 100; i++)
  {
    for(int j = 0; j < 1000; j++)
    {
      minhaGeracao.evoluir();
    }
    std::cout << 1000*(i+1) << " - " << minhaGeracao.pegarMaisAdaptado().valorDeAdaptacao_ << "\n";
  }
}
