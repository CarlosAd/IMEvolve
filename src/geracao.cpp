#include "geracao.h"

Geracao::Geracao(FuncaoObjetivo &ifuncaoObjetivo,
                 SeletorNatural &iseletorNatural,
                 FuncaoMutacao &ifuncaoMutacao,
                 FuncaoReproducao &ifuncaoReproducao) :
                 funcaoObjetivo (ifuncaoObjetivo),
                 seletorNatural (iseletorNatural),
                 funcaoMutacao (ifuncaoMutacao),
                 funcaoReproducao (ifuncaoReproducao) {
}

void Geracao::gerarPopulacao(const unsigned int& itamanhoCromossomo,
                             const unsigned int& itamanhoPopulacao,
                             const unsigned int& ielitismo) {
  tamanhoPopulacao = itamanhoPopulacao;
  elitismo = ielitismo;
  populacaoAuxiliar.resize(tamanhoPopulacao - elitismo, Individuo(itamanhoCromossomo));

  for (int i = 0; i < itamanhoPopulacao; i++) {
    populacao.push_back(Individuo(itamanhoCromossomo));
  }
}
