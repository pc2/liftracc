# - Find Goto2 blas library.
# This module finds an installed Goto2 blas library.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  GOTO2_FOUND            - Set to TRUE if Goto2 lib was found.
#  GOTO2_ROOT_DIR         - base directory of Goto2 blas library.
#  GOTO2_INCLUDE_DIRS     - Goto2 include directories.
#  GOTO2_LIBRARY_DIR      - Goto2 library directory.

set(GOTO2_FOUND false)

find_path(GOTO2_ROOT_DIR
  NAMES cblas.h
  NAMES libgoto2.a
  NAMES libgoto2.so
  PATHS $ENV{GOTO2_ROOT_DIR}
  DOC "Goto2 BLAS library base directory"
)

if(NOT GOTO2_ROOT_DIR)
  message(WARNING
    "\nGoto2 BLAS library not found!\n"
    "Please set the environment variable GOTO2_ROOT_DIR to the base directory"
    " of the Goto2 blas library. Make sure libgoto2.a and libgoto2.so are"
    " present in that directory.\n"
  )
else(NOT GOTO2_ROOT_DIR)
  message(STATUS "GOTO2_ROOT_DIR: ${GOTO2_ROOT_DIR}")

  set(GOTO2_INCLUDE_DIRS ${GOTO2_ROOT_DIR})
  set(GOTO2_LIBRARY_DIR ${GOTO2_ROOT_DIR})

  set(GOTO2_FOUND true)
endif(NOT GOTO2_ROOT_DIR)

