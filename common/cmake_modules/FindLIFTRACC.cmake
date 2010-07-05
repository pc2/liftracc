# - Find liftracc library.
# This module finds a compiled liftracc library.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  LIFTRACC_FOUND            - Set to TRUE if liftracc lib was found.
#  LIFTRACC_ROOT_DIR         - base directory of liftracc library source.
#  LIFTRACC_BUILD_DIR        - base directory where liftracc library was build.
#  LIFTRACC_INCLUDE_DIR      - liftracc include directory.
#  LIFTRACC_LIBRARY_DIR      - liftracc library directory.

set(LIFTRACC_FOUND false)

# Add the convenience use file if available.
set(LIFTRACC_USE_FILE "")
get_filename_component(TMP_CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)
message(STATUS "TMP_CURRENT_LIST_DIR: ${TMP_CURRENT_LIST_DIR}")
# Prefer an existing customized version
if(EXISTS "${TMP_CURRENT_LIST_DIR}/UseLIFTRACC.cmake")
  set(LIFTRACC_USE_FILE "${TMP_CURRENT_LIST_DIR}/UseLIFTRACC.cmake")
else(EXISTS "${TMP_CURRENT_LIST_DIR}/UseLIFTRACC.cmake")
  set(LIFTRACC_USE_FILE UseLIFTRACC.cmake)
endif(EXISTS "${TMP_CURRENT_LIST_DIR}/UseLIFTRACC.cmake")

find_path(LIFTRACC_ROOT_DIR
  NAMES src/liftracc.h
  PATHS $ENV{LIFTRACC_ROOT_DIR}
  DOC "liftracc library base directory"
)

find_path(LIFTRACC_BUILD_DIR
  NAMES libliftracc.so
  PATHS $ENV{LIFTRACC_BUILD_DIR}
  DOC "liftracc library build directory"
)

if(NOT LIFTRACC_ROOT_DIR OR NOT LIFTRACC_BUILD_DIR)
  message(WARNING
    "\nliftracc library not found!\n"
    "Please set the environment variable LIFTRACC_ROOT_DIR to the base directory"
    " of the liftracc library. Make sure src/liftracc.h is present in that directory."
    " Set the environment variable LIFTRACC_BUILD_DIR to the directory in which"
    " the liftracc library was build. Make sure libliftracc.so is present in that directory.\n"
  )
else(NOT LIFTRACC_ROOT_DIR OR NOT LIFTRACC_BUILD_DIR)
  message(STATUS "LIFTRACC_ROOT_DIR: ${LIFTRACC_ROOT_DIR}")
  message(STATUS "LIFTRACC_BUILD_DIR: ${LIFTRACC_BUILD_DIR}")

  set(LIFTRACC_INCLUDE_DIR ${LIFTRACC_ROOT_DIR}/src)
  set(LIFTRACC_LIBRARY_DIR ${LIFTRACC_BUILD_DIR})

  set(LIFTRACC_FOUND true)
endif(NOT LIFTRACC_ROOT_DIR OR NOT LIFTRACC_BUILD_DIR)

