# - Find ATLAS blas library.
# This module finds a installed ATALS blas library.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  ATLAS_FOUND            - Set to TRUE if ATLAS blas lib was found.
#  ATLAS_ROOT_DIR         - base directory of ATLAS blas library source.
#  ATLAS_BUILD_DIR        - base directory where ATLAS blas library was build.
#  ATLAS_INCLUDE_DIRS     - ATLAS include directories.
#  ATLAS_LIBRARY_DIR      - ATLAS library directory.

set(ATLAS_FOUND false)

find_path(ATLAS_ROOT_DIR
  NAMES include/atlas_level1.h
  NAMES include/atlas_level2.h
  NAMES include/atlas_level3.h
  PATHS $ENV{ATLAS_ROOT_DIR}
  DOC "ATLAS BLAS library base directory"
)

find_path(ATLAS_BUILD_DIR
  NAMES lib/libatlas.so
  PATHS $ENV{ATLAS_BUILD_DIR}
  DOC "ATLAS library build directory"
)

if(NOT ATLAS_ROOT_DIR OR NOT ATLAS_BUILD_DIR)
  message(WARNING
    "\nATLAS BLAS library not found!\n"
    "Please set the environment variable ATLAS_ROOT_DIR to the base directory"
    " of the ATLAS blas library. Make sure include/atlas_level1.h, include/atlas_level2.h and"
    " include/atlas_level3.h are present in that directory."
    " Set the environment variable ATLAS_BUILD_DIR to the directory in which"
    " the ATLAS library was build. Make sure lib/libatlas.so is present in that directory.\n"
  )
else(NOT ATLAS_ROOT_DIR OR NOT ATLAS_BUILD_DIR)
  message(STATUS "ATLAS_ROOT_DIR: ${ATLAS_ROOT_DIR}")
  message(STATUS "ATLAS_BUILD_DIR: ${ATLAS_BUILD_DIR}")

  set(ATLAS_INCLUDE_DIRS ${ATLAS_ROOT_DIR}/include ${ATLAS_BUILD_DIR}/include)
  set(ATLAS_LIBRARY_DIR ${ATLAS_BUILD_DIR}/lib)

  set(ATLAS_FOUND true)
endif(NOT ATLAS_ROOT_DIR OR NOT ATLAS_BUILD_DIR)

