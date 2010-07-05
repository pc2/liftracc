
add_executable(tune_dgemm
  ${PROJECT_SOURCE_DIR}/tune/tune_dgemm.cpp
)

target_link_libraries(tune_dgemm
  liftracc
)

add_executable(tune_ddot
  ${PROJECT_SOURCE_DIR}/tune/tune_ddot.cpp
)

target_link_libraries(tune_ddot
  liftracc
)

add_executable(tune_daxpy
  ${PROJECT_SOURCE_DIR}/tune/tune_daxpy.cpp
)

target_link_libraries(tune_daxpy
  liftracc
)

add_executable(tune_dscal
  ${PROJECT_SOURCE_DIR}/tune/tune_dscal.cpp
)

target_link_libraries(tune_dscal
  liftracc
)

add_executable(tune_idamax
  ${PROJECT_SOURCE_DIR}/tune/tune_idamax.cpp
)

target_link_libraries(tune_idamax
  liftracc
)

add_custom_command(
  TARGET tune_dgemm POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/tune/tune_dgemm.sh ${PROJECT_BINARY_DIR}/tune_dgemm.sh
  COMMENT "copy tune_dgemm.sh"
)

add_custom_command(
  TARGET tune_ddot POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/tune/tune_ddot.sh ${PROJECT_BINARY_DIR}/tune_ddot.sh
  COMMENT "copy tune_ddot.sh"
)

add_custom_command(
  TARGET tune_daxpy POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/tune/tune_daxpy.sh ${PROJECT_BINARY_DIR}/tune_daxpy.sh
  COMMENT "copy tune_daxpy.sh"
)

add_custom_command(
  TARGET tune_dscal POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/tune/tune_dscal.sh ${PROJECT_BINARY_DIR}/tune_dscal.sh
  COMMENT "copy tune_dscal.sh"
)

add_custom_command(
  TARGET tune_idamax POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/tune/tune_idamax.sh ${PROJECT_BINARY_DIR}/tune_idamax.sh
  COMMENT "copy tune_idamax.sh"
)

