#include <mpi.h>
#include <math.h>
#include "minha_geracao.h"

int main() {
  int n_processos, meu_rank;
  int n_individuos_por_processo;
  unsigned char* buffer;
  int buffer_size;
  double* valores_adaptacao;

  MPI_Status status;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &n_processos);
  MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);

  Geracao* geracao = new MinhaGeracao();

  n_individuos_por_processo = ceil((float)geracao->getTamanhoPopulacao() / (n_processos - 1));
  buffer = new unsigned char[n_individuos_por_processo * geracao->getTamanhoCromossomo()];
  valores_adaptacao = new double[n_individuos_por_processo];

  if (meu_rank == 0) {
    int max_buffer;
    int indice_individuo, indice_inicial;
    geracao->gerarPopulacao();
    while (!geracao->parar()) {
      geracao->preProcessamento();
      buffer_size = 0;

      indice_individuo = 0;
      for (int rank = 1; rank < n_processos; rank++) {
        indice_inicial = indice_individuo;
        if (rank <= (geracao->getTamanhoPopulacao() % (n_processos - 1))) {
          max_buffer = ((geracao->getTamanhoPopulacao() / (n_processos - 1)) + 1) * geracao->getTamanhoCromossomo();
        }
        else {
          max_buffer = ((geracao->getTamanhoPopulacao() / (n_processos - 1))) * geracao->getTamanhoCromossomo();
        }

        while (buffer_size < max_buffer) {
          for (int gene = 0; gene < geracao->getTamanhoCromossomo(); gene++) {
            buffer[buffer_size] = geracao->getPopulacao()[indice_individuo][gene];
            buffer_size++;
          }
          indice_individuo++;
        }

        MPI_Send(buffer, buffer_size, MPI_UNSIGNED_CHAR, rank, indice_inicial, MPI_COMM_WORLD);
        buffer_size = 0;
      }

      for (int i = 0; i < (n_processos - 1); i++) {
        MPI_Recv(valores_adaptacao, n_individuos_por_processo, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_DOUBLE, &buffer_size);

        geracao->atribuirValoresAdaptacao(status.MPI_TAG, buffer_size, valores_adaptacao);
      }
      
      geracao->evoluir();

      geracao->posProcessamento();
    }

    for (int rank_destino = 1; rank_destino < n_processos; rank_destino++) {
      MPI_Send(NULL, 0, MPI_INT, rank_destino, geracao->getTamanhoPopulacao(), MPI_COMM_WORLD);
    }
  }
  else {
    Individuo individuo;
    while (true) {
      MPI_Recv(buffer, n_individuos_por_processo * geracao->getTamanhoCromossomo(), MPI_UNSIGNED_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      if (status.MPI_TAG == geracao->getTamanhoPopulacao()) {
        break;
      }

      MPI_Get_count(&status, MPI_UNSIGNED_CHAR, &buffer_size);

      buffer_size = (buffer_size / geracao->getTamanhoCromossomo());

      for (int id_individuo = 0; id_individuo < buffer_size; id_individuo++) {
        individuo.alterarGenes(buffer + (id_individuo * geracao->getTamanhoCromossomo()), geracao->getTamanhoCromossomo());
        valores_adaptacao[id_individuo] = geracao->calcularAdaptacao(meu_rank, individuo);
      }

      MPI_Send(valores_adaptacao, buffer_size, MPI_DOUBLE, 0, status.MPI_TAG, MPI_COMM_WORLD);
    }
  }

  delete[] buffer;
  delete[] valores_adaptacao;
  delete geracao;

  MPI_Finalize();
}
