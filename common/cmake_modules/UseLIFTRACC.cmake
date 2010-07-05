# - Convenience include for using the liftracc library
# Detects if liftracc was found
# and set the appropriate libs, incdirs, flags etc.
#
# Author: Manuel Niekamp
# Email:  niekma@upb.de
#

if(LIFTRACC_FOUND)
  
  if(LIFTRACC_INCLUDE_DIR)
    include_directories(${LIFTRACC_INCLUDE_DIR})
  endif(LIFTRACC_INCLUDE_DIR)
    
  if(LIFTRACC_LIBRARY_DIR)
    link_directories(${LIFTRACC_LIBRARY_DIR})
  endif(LIFTRACC_LIBRARY_DIR)

else(LIFTRACC_FOUND)

  message(FATAL_ERROR "liftracc library was not found!")

endif(LIFTRACC_FOUND)

