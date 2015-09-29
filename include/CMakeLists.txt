include_directories("${PROJECT_SOURCE_DIR}/src")

set(LIBS
  #${PROJECT_SOURCE_DIR}/src/funcaoObjetivo.cpp
  ${PROJECT_SOURCE_DIR}/src/individuo.cpp
  #${PROJECT_SOURCE_DIR}/src/geracao.cpp
  ${PROJECT_SOURCE_DIR}/src/funcaoReproducao.cpp
  ${PROJECT_SOURCE_DIR}/src/funcaoMutacao.cpp
  ${PROJECT_SOURCE_DIR}/src/seletorNatural.cpp

  #ADICIONE OUTROS CPPS ACIMA
)

add_library(bibliotecas ${LIBS})
