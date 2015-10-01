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
  FuncaoMutacao mfm (0.1);

  Geracao minhaGeracao (mfo, msn, mfm, mfr);
  minhaGeracao.gerarPopulacao (5, 20, 3);
}
