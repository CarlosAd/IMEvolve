#include "../include/individuo.h"
#include <iostream>

int main () {
  Individuo i (10);
  for (int index = 0; index < i.tamanho(); index++) {
    std::cout << static_cast<int>(i[index]) << std::endl;
  }
  std::cout << "Hello Darwin!" << std::endl;

  return 0;
}
