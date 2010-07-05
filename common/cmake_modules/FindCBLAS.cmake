# - Find cblas/blas library.
# This module finds an installed cblas/blas library.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  CBLAS_FOUND            - Set to TRUE if cblas/blas lib was found.
#  CBLAS_ROOT_DIR         - base directory of cblas/blas library.
#  CBLAS_INCLUDE_DIRS     - CBLAS include directories.
#  CBLAS_LIBRARY_DIR      - CBLAS library directory.
#  CBLAS_LIBRARY          - static CBLAS library path+name.
#  BLAS_LIBRARY           - static BLAS library path+name.

set(CBLAS_FOUND false)

find_path(CBLAS_ROOT_DIR
  NAMES src/cblas.h
  NAMES libcblas.a
  NAMES libblas.a
  PATHS $ENV{CBLAS_ROOT_DIR}
  DOC "CBLAS/BLAS library base directory"
)

if(NOT CBLAS_ROOT_DIR)
  message(FATAL_ERROR
    "\nCBLAS/BLAS library not found!\n"
    "Please set the environment variable CBLAS_ROOT_DIR to the base directory"
    " of the cblas/blas library. Make sure libblas.a and libcblas.a are"
    " present in that directory.\n"
  )
else(NOT CBLAS_ROOT_DIR)
  message(STATUS "CBLAS_ROOT_DIR: ${CBLAS_ROOT_DIR}")

  set(CBLAS_INCLUDE_DIRS ${CBLAS_ROOT_DIR}/src)
  set(CBLAS_LIBRARY_DIR ${CBLAS_ROOT_DIR})
  set(CBLAS_LIBRARY ${CBLAS_ROOT_DIR}/libcblas.a)
  set(BLAS_LIBRARY ${CBLAS_ROOT_DIR}/libblas.a)

  set(CBLAS_FOUND true)

endif(NOT CBLAS_ROOT_DIR)

