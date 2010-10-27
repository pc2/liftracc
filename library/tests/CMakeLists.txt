#####
# general tests
#

add_executable(test_timers
  ${PROJECT_SOURCE_DIR}/tests/test_timers.cpp
)
target_link_libraries(test_timers
  rt
)

add_executable(test01
  ${PROJECT_SOURCE_DIR}/tests/test01.cpp
)
target_link_libraries(test01
  liftracc
)

add_executable(test02
  ${PROJECT_SOURCE_DIR}/tests/test02.cpp
)
target_link_libraries(test02
  cblas
  cblas_inner
  blas
)

add_executable(test03
  ${PROJECT_SOURCE_DIR}/tests/test03.cpp
)
target_link_libraries(test03
  csxl_mkl
  dl
)

add_executable(test04
  ${PROJECT_SOURCE_DIR}/tests/test04.cpp
)
target_link_libraries(test04
  liftracc
  dl
)

add_executable(test04a
  ${PROJECT_SOURCE_DIR}/tests/test04a.cpp
)
target_link_libraries(test04a
  liftracc
  dl
)

#####
# dgemm tests
#

add_executable(test05
  ${PROJECT_SOURCE_DIR}/tests/test05.cpp
)
target_link_libraries(test05
  liftracc
)

add_executable(test06
  ${PROJECT_SOURCE_DIR}/tests/test06.cpp
)
target_link_libraries(test06
  liftracc
)

add_executable(test07
  ${PROJECT_SOURCE_DIR}/tests/test07.cpp
)
target_link_libraries(test07
  liftracc
)

add_executable(test08
  ${PROJECT_SOURCE_DIR}/tests/test08.cpp
)
target_link_libraries(test08
  liftracc
)

add_executable(test09
  ${PROJECT_SOURCE_DIR}/tests/test09.cpp
)
target_link_libraries(test09
  cublas
  liftracc
)

add_executable(dgemm_cblas_atlas
  ${PROJECT_SOURCE_DIR}/tests/dgemm_cblas_atlas.cpp
)
target_link_libraries(dgemm_cblas_atlas
  cblas
  cblas_inner
  blas
  atlas
  dl
)

#####
# 2^n tests
#

add_executable(dgemm_std_cblas
  ${PROJECT_SOURCE_DIR}/tests/dgemm_std_cblas.cpp
)
target_link_libraries(dgemm_std_cblas
  liftracc
)

add_executable(dgemm_std_atlas
  ${PROJECT_SOURCE_DIR}/tests/dgemm_std_atlas.cpp
)
target_link_libraries(dgemm_std_atlas
  liftracc
)

add_executable(dgemm_std_cubla
  ${PROJECT_SOURCE_DIR}/tests/dgemm_std_cubla.cpp
)
target_link_libraries(dgemm_std_cubla
  cublas
  liftracc
)

add_executable(dgemm_std_goto2
  ${PROJECT_SOURCE_DIR}/tests/dgemm_std_goto2.cpp
)
target_link_libraries(dgemm_std_goto2
  liftracc
)

add_executable(dgemm_std_clear
  ${PROJECT_SOURCE_DIR}/tests/dgemm_std_clear.cpp
)
target_link_libraries(dgemm_std_clear
  liftracc
)

add_executable(ddot_std_cblas
  ${PROJECT_SOURCE_DIR}/tests/ddot_std_cblas.cpp
)
target_link_libraries(ddot_std_cblas
  liftracc
)

add_executable(ddot_std_atlas
  ${PROJECT_SOURCE_DIR}/tests/ddot_std_atlas.cpp
)
target_link_libraries(ddot_std_atlas
  liftracc
)

add_executable(ddot_std_cubla
  ${PROJECT_SOURCE_DIR}/tests/ddot_std_cubla.cpp
)
target_link_libraries(ddot_std_cubla
  cublas
  liftracc
)

add_executable(ddot_std_goto2
  ${PROJECT_SOURCE_DIR}/tests/ddot_std_goto2.cpp
)
target_link_libraries(ddot_std_goto2
  liftracc
)

add_executable(daxpy_std_cblas
  ${PROJECT_SOURCE_DIR}/tests/daxpy_std_cblas.cpp
)
target_link_libraries(daxpy_std_cblas
  liftracc
)

add_executable(daxpy_std_atlas
  ${PROJECT_SOURCE_DIR}/tests/daxpy_std_atlas.cpp
)
target_link_libraries(daxpy_std_atlas
  liftracc
)

add_executable(daxpy_std_cubla
  ${PROJECT_SOURCE_DIR}/tests/daxpy_std_cubla.cpp
)
target_link_libraries(daxpy_std_cubla
  cublas
  liftracc
)

add_executable(daxpy_std_goto2
  ${PROJECT_SOURCE_DIR}/tests/daxpy_std_goto2.cpp
)
target_link_libraries(daxpy_std_goto2
  liftracc
)

#####
# ddot tests
#

add_executable(test10
  ${PROJECT_SOURCE_DIR}/tests/test10.cpp
)
target_link_libraries(test10
  liftracc
)

add_executable(test11
  ${PROJECT_SOURCE_DIR}/tests/test11.cpp
)
target_link_libraries(test11
  liftracc
)

add_executable(test12
  ${PROJECT_SOURCE_DIR}/tests/test12.cpp
)
target_link_libraries(test12
  liftracc
)

add_executable(test13
  ${PROJECT_SOURCE_DIR}/tests/test13.cpp
)
target_link_libraries(test13
  cublas
  liftracc
)

