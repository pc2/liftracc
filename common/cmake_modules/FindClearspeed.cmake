# - Find Clearspeed SDK.
# This module finds an installed Clearspeed SDK.
#
# Author: Manuel Niekamp
# Email: niekma@upb.de
#
# The following variables are set after the configuration is done:
#
#  CLEARSPEED_FOUND            - Set to TRUE if Clearspeed SDK was found.
#  CLEARSPEED_ROOT_DIR         - base directory of Clearspeed SDK.
#  CLEARSPEED_INCLUDE_DIRS     - Clearspeed SDK include directories.
#  CLEARSPEED_LIBRARY_DIR      - Clearspeed SDK library directory.

set(CLEARSPEED_FOUND false)

find_path(CLEARSPEED_ROOT_DIR
  NAMES include/card/cn/csxl_blas.h
  NAMES lib/libcsxl_mkl.so
  PATHS $ENV{CLEARSPEED_ROOT_DIR}
  DOC "Clearspeed SDK base directory"
)

if(NOT CLEARSPEED_ROOT_DIR)
  message(WARNING
    "\nClearspeed SDK not found!\n"
    "Please set the environment variable CLEARSPEED_ROOT_DIR to the base directory"
    " of the Clearspeed SDK. Make sure include/card/cn/csxl_blas.h and lib/libcsxl_mkl.so are"
    " present in that directory.\n"
  )
else(NOT CLEARSPEED_ROOT_DIR)
  message(STATUS "CLEARSPEED_ROOT_DIR: ${CLEARSPEED_ROOT_DIR}")

  set(CLEARSPEED_INCLUDE_DIRS
    ${CLEARSPEED_ROOT_DIR}/include
    ${CLEARSPEED_ROOT_DIR}/include/card/cn
    ${CLEARSPEED_ROOT_DIR}/include/host
  )
  set(CLEARSPEED_LIBRARY_DIR ${CLEARSPEED_ROOT_DIR}/lib)

  set(CLEARSPEED_FOUND true)
endif(NOT CLEARSPEED_ROOT_DIR)

