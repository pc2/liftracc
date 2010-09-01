# - Find cblas library.
# This module finds an installed cblas library.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  CBLAS_FOUND            - Set to TRUE if cblas lib was found.
#  CBLAS_ROOT_DIR         - base directory of cblas library.
#  CBLAS_INCLUDE_DIRS     - CBLAS include directories.
#  CBLAS_LIBRARY_DIR      - CBLAS library directory.
#  CBLAS_LIBRARY          - static CBLAS library path+name.

set(CBLAS_FOUND false)

find_path(CBLAS_ROOT_DIR
  NAMES src/cblas.h
  NAMES libcblas.a
  NAMES libcblas.so
  PATHS $ENV{CBLAS_ROOT_DIR}
  DOC "CBLAS library base directory"
)

if(NOT CBLAS_ROOT_DIR)
  message(FATAL_ERROR
    "\nCBLAS library not found!\n"
    "Please set the environment variable CBLAS_ROOT_DIR to the base directory"
    " of the cblas library. Make sure libcblas.a and libcblas.so are"
    " present in that directory.\n"
  )
else(NOT CBLAS_ROOT_DIR)
  message(STATUS "CBLAS_ROOT_DIR: ${CBLAS_ROOT_DIR}")

  set(CBLAS_INCLUDE_DIRS ${CBLAS_ROOT_DIR}/src)
  set(CBLAS_LIBRARY_DIR ${CBLAS_ROOT_DIR})
  set(CBLAS_LIBRARY ${CBLAS_ROOT_DIR}/libcblas.a)

  set(CBLAS_FOUND true)

endif(NOT CBLAS_ROOT_DIR)

