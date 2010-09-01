cmake_minimum_required(VERSION 2.6.4)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

project(testapps)

#find_package(Pin REQUIRED)
#include(${PIN_USE_FILE})

find_package(LIFTRACC REQUIRED)
include(${LIFTRACC_USE_FILE})

include_directories(
  $ENV{HOME}/include
  ${LIFTRACC_ROOT_DIR}/../common/boost_program_options/include
)

link_directories(
  $ENV{HOME}/lib
  ${LIFTRACC_ROOT_DIR}/../common/boost_program_options/build
)

add_library(testlib SHARED
  ${PROJECT_SOURCE_DIR}/src/testlib.c
)

add_library(testlib_interposer SHARED
  ${PROJECT_SOURCE_DIR}/src/testlib_interposer.c
)

target_link_libraries(testlib_interposer
  dl
)

add_custom_command(TARGET testlib_interposer POST_BUILD
  COMMENT "Copying start script interpose.sh"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/src/interpose.sh ${PROJECT_BINARY_DIR}/interpose.sh
)

add_custom_command(TARGET testlib_interposer POST_BUILD
  COMMENT "Copying start script interpose_dlsym.sh"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/src/interpose_dlsym.sh ${PROJECT_BINARY_DIR}/interpose_dlsym.sh
)

add_executable(test_app
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(test_app
  boost_program_options
  testlib
)

add_executable(test_app_sym
  ${PROJECT_SOURCE_DIR}/src/main_dlsym.cpp
)

target_link_libraries(test_app_sym
  boost_program_options
  dl
)

#add_pintool(proctrace
#  ${PROJECT_SOURCE_DIR}/src/proctrace.cpp
#)

#add_pintool(replace_fibrec
#  ${PROJECT_SOURCE_DIR}/src/replace_fibrec.cpp
#)

add_executable(show_info
  ${PROJECT_SOURCE_DIR}/src/show_info.c
)

target_link_libraries(show_info
  liftracc
)
