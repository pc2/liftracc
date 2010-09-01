# - Find blas library.
# This module finds an installed blas library.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  BLAS_FOUND            - Set to TRUE if blas lib was found.
#  BLAS_ROOT_DIR         - base directory of blas library.
#  BLAS_INCLUDE_DIRS     - BLAS include directories.
#  BLAS_LIBRARY_DIR      - BLAS library directory.
#  BLAS_LIBRARY          - static BLAS library path+name.

set(BLAS_FOUND false)

find_path(BLAS_ROOT_DIR
  NAMES libblas.a
  NAMES libblas.so
  PATHS $ENV{BLAS_ROOT_DIR}
  DOC "BLAS library base directory"
)

if(NOT BLAS_ROOT_DIR)
  message(FATAL_ERROR
    "\nBLAS library not found!\n"
    "Please set the environment variable BLAS_ROOT_DIR to the base directory"
    " of the blas library. Make sure libblas.a and libblas.so are"
    " present in that directory.\n"
  )
else(NOT BLAS_ROOT_DIR)
  message(STATUS "BLAS_ROOT_DIR: ${BLAS_ROOT_DIR}")

  set(BLAS_INCLUDE_DIRS ${BLAS_ROOT_DIR})
  set(BLAS_LIBRARY_DIR ${BLAS_ROOT_DIR})
  set(BLAS_LIBRARY ${BLAS_ROOT_DIR}/libblas.a)

  set(BLAS_FOUND true)

endif(NOT BLAS_ROOT_DIR)

