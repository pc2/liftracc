cmake_minimum_required(VERSION 2.6.4)

project(boost_program_options)

include_directories(
  $ENV{HOME}/include
)

add_library(boost_program_options
  ${PROJECT_SOURCE_DIR}/src/program_options/src/cmdline.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/config_file.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/convert.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/options_description.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/parsers.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/positional_options.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/utf8_codecvt_facet.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/value_semantic.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/variables_map.cpp
  ${PROJECT_SOURCE_DIR}/src/program_options/src/winmain.cpp
)

