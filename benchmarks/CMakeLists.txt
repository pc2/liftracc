cmake_minimum_required(VERSION 2.6.4)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

project(benchmarks)

find_package(LIFTRACC REQUIRED)
include(${LIFTRACC_USE_FILE})

find_package(BLAS REQUIRED)
find_package(CBLAS REQUIRED)
find_package(Goto2)

include_directories(
  ${BLAS_INCLUDE_DIRS}
  ${CBLAS_INCLUDE_DIRS}
  ${GOTO2_INCLUDE_DIRS}
)

link_directories(
  ${BLAS_LIBRARY_DIR}
  ${CBLAS_LIBRARY_DIR}
  ${GOTO2_LIBRARY_DIR}
)

add_executable(linpack-new
  ${PROJECT_SOURCE_DIR}/src/linpack-new.c
)

target_link_libraries(linpack-new
  m
)

add_executable(linpack-new-mod
  ${PROJECT_SOURCE_DIR}/src/linpack-new-mod.c
)

target_link_libraries(linpack-new-mod
  m
)

add_executable(linpack-liftracc
  ${PROJECT_SOURCE_DIR}/src/linpack-liftracc.c
)

target_link_libraries(linpack-liftracc
  liftracc
)

add_executable(linpack-testing
  ${PROJECT_SOURCE_DIR}/src/linpack-testing.c
)

target_link_libraries(linpack-testing
  liftracc
)

set(LIFTRACC_TESTING_SELECT "cblas" CACHE STRING "Options: cblas, liftracc.")
string(TOUPPER "${LIFTRACC_TESTING_SELECT}" SELECT_VALUE)
add_definitions(-D_SELECT_${SELECT_VALUE}_)

add_custom_command(
  TARGET linpack-liftracc POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${PROJECT_SOURCE_DIR}/src/linpack-liftracc.sh
  ${PROJECT_BINARY_DIR}/linpack-liftracc.sh
  COMMENT "copy linpack-liftracc.sh"
)

add_executable(linpack-cblas
  ${PROJECT_SOURCE_DIR}/src/linpack-cblas.c
)

target_link_libraries(linpack-cblas
  cblas
  blas
)

