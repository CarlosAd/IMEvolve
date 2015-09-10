include_directories("${PROJECT_SOURCE_DIR}/src")

set(LIBS
  ${PROJECT_SOURCE_DIR}/src/funcaoObjetivo.cpp
  ${PROJECT_SOURCE_DIR}/src/individuo.cpp

  #ADICIONE OUTROS CPPS ACIMA
)

add_library(bibliotecas ${LIBS})
