#include "minha_geracao.h"

double MinhaFuncaoObjetivo::operator() (const Individuo& avaliado) {
  return 0.0f;
}

MinhaGeracao::MinhaGeracao() : Geracao() {
}

bool MinhaGeracao::parar() {
  return false;
}

void MinhaGeracao::preProcessamento() {
}

void MinhaGeracao::posProcessamento() {
}
