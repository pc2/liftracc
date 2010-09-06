#####
# libliftracc cmake project file
#
cmake_minimum_required(VERSION 2.6.4)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

project(libliftracc)
set(CMAKE_CONFIGURATION_TYPES "Release Debug Profiling")

if($ENV{CC})
  set(CMAKE_CC_COMPILER $ENV{CC})
endif($ENV{CC})

if($ENV{CXX})
  set(CMAKE_CXX_COMPILER $ENV{CXX})
endif($ENV{CXX})

#add_definitions(-Wall -O2 -fno-strict-aliasing)
add_definitions(-Wall -O0 -fno-strict-aliasing)

set(CMAKE_C_FLAGS_PROFILING          "-g -pg")
set(CMAKE_CXX_FLAGS_PROFILING        "-g -pg")

set(LIFTRACC_SOURCE
  ${PROJECT_SOURCE_DIR}/src/liftracc.c
)

#####
# library options - configure with ccmake or cmake-gui
#
option(LIFTRACC_DEBUG_MESSAGES "Turn on/off debug messages in general" ON)
if(LIFTRACC_DEBUG_MESSAGES)
  add_definitions(-D_DEBUG_)
endif(LIFTRACC_DEBUG_MESSAGES)

set(LIFTRACC_DEBUG_LEVEL "2" CACHE STRING "0-NONE  1-ERROR  2-ERROR,MSG  3-ERROR,MSG,WARN  4-ERROR,MSG,WARN,INFO")
add_definitions(-D_DEBUG_LEVEL_=${LIFTRACC_DEBUG_LEVEL})

set(LIFTRACC_PROFILING "3" CACHE STRING "0-OFF  1-OUTER_CALL  2-SELECT_CALL  3-INNER_CALL  4-LUT_INIT")
if(LIFTRACC_PROFILING)
  add_definitions(-D_LIFTRACC_PROFILING_=${LIFTRACC_PROFILING})
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_profiling_autogen.c
    ${PROJECT_SOURCE_DIR}/src/liftracc_calltest_normal.c
  )
endif(LIFTRACC_PROFILING)

option(LIFTRACC_MEASURE_TICKS "Do measurings in cpu ticks only. (Profiling must be on, too)" ON)
if(LIFTRACC_MEASURE_TICKS AND LIFTRACC_PROFILING)
  add_definitions(-D_LIFTRACC_MEASURE_TICKS_)
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_profiling_tks.c
  )
else(LIFTRACC_MEASURE_TICKS AND LIFTRACC_PROFILING)
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_profiling.c
  )
endif(LIFTRACC_MEASURE_TICKS AND LIFTRACC_PROFILING)

option(LIFTRACC_TESTING "If turned on use liftracc_testing.c instead of liftracc_autogen.c" ON)
if(LIFTRACC_TESTING)
  add_definitions(-D_LIFTRACC_TESTING_)
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_testing.c
  )
else(LIFTRACC_TESTING)
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_autogen.c
  )
endif(LIFTRACC_TESTING)

option(LIFTRACC_MKL_INTERFACE "Enable the MKL interface" ON)
if(LIFTRACC_MKL_INTERFACE)
  add_definitions(-D_LIFTRACC_MKL_INTERFACE_)
endif(LIFTRACC_MKL_INTERFACE)

option(LIFTRACC_CBLAS_INTERFACE "Enable the CBLAS interface" ON)
if(LIFTRACC_CBLAS_INTERFACE)
  add_definitions(-D_LIFTRACC_CBLAS_INTERFACE_)
endif(LIFTRACC_CBLAS_INTERFACE)

option(LIFTRACC_SELECTOR_NEW "Compile with new selector mechanism (default)" ON)
if(LIFTRACC_SELECTOR_NEW)
  add_definitions(-D_LIFTRACC_SELECTOR_NEW_)
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_selector.c
    ${PROJECT_SOURCE_DIR}/src/liftracc_selector_autogen.c
  )
else(LIFTRACC_SELECTOR_NEW)
  list(APPEND LIFTRACC_SOURCE
    ${PROJECT_SOURCE_DIR}/src/liftracc_selector_old.c
  )
endif(LIFTRACC_SELECTOR_NEW)

option(LIFTRACC_AUTOMODE "Enable Auto mode. Decision based on time not priorities." ON)
if(LIFTRACC_AUTOMODE)
  add_definitions(-D_LIFTRACC_AUTOMODE_)
endif(LIFTRACC_AUTOMODE)

option(LIFTRACC_AUTOMODE_TRAINING "Enable training mode to aquire data for automode. (Set LIFTRACC_AUTOMODE=ON and LIFTRACC_PROFILING=3)" ON)
if(LIFTRACC_AUTOMODE_TRAINING AND LIFTRACC_AUTOMODE AND LIFTRACC_PROFILING)
  add_definitions(-D_LIFTRACC_AUTOMODE_TRAINING_)
endif(LIFTRACC_AUTOMODE_TRAINING AND LIFTRACC_AUTOMODE AND LIFTRACC_PROFILING)

option(LIFTRACC_USE_PLUGIN "Enable this, if you plan to select plugin via environment variable." OFF)
if(LIFTRACC_USE_PLUGIN)
  add_definitions(-D_LIFTRACC_USE_PLUGIN_)
endif(LIFTRACC_USE_PLUGIN)

#####
# find different blas libraries installed on system
# FindPackage files can be found in ./cmake/modules
#
find_package(BLAS REQUIRED)
find_package(CBLAS REQUIRED)
find_package(CUDA)
if(CUDA_TOOLKIT_ROOT_DIR)
  set(CUDA_LIBRARY_DIR ${CUDA_TOOLKIT_ROOT_DIR}/lib ${CUDA_TOOLKIT_ROOT_DIR}/lib64)
endif(CUDA_TOOLKIT_ROOT_DIR)
find_package(Goto2)
find_package(ATLAS)
find_package(Clearspeed)

#####
# project include directories
#
include_directories(
#  $ENV{HOME}/include
  ${PROJECT_SOURCE_DIR}/src
  ${BLAS_INCLUDE_DIRS}
  ${CBLAS_INCLUDE_DIRS}
  ${GOTO2_INCLUDE_DIRS}
  ${CUDA_INCLUDE_DIRS}
  ${ATLAS_INCLUDE_DIRS}
)

#####
# project link directories
#
link_directories(
#  $ENV{HOME}/lib
  ${PROJECT_BINARY_DIR}
  ${CUDA_LIBRARY_DIR}
  ${BLAS_LIBRARY_DIR}
  ${CBLAS_LIBRARY_DIR}
  ${ATLAS_LIBRARY_DIR}
  ${GOTO2_LIBRARY_DIR}
  ${CLEARSPEED_LIBRARY_DIR}
)

#####
# main library definition
#
add_library(liftracc SHARED
  ${LIFTRACC_SOURCE}
)

target_link_libraries(liftracc
  dl
  rt
)

macro(ADD_LIFTRACC_PLUGIN plugin_name)
  set(_LINK_LIBS "")
  set(_SOURCE_FILES "")
  set(_LINK_FLAG "0")
  
  foreach(_ARG ${ARGN})
    if(${_ARG} STREQUAL "LINK")
      set(_LINK_FLAG "1")
    else(${_ARG} STREQUAL "LINK")
      if(_LINK_FLAG)
        list(APPEND _LINK_LIBS ${_ARG})
      else(_LINK_FLAG)
        list(APPEND _SOURCE_FILES ${_ARG})
      endif(_LINK_FLAG)
    endif(${_ARG} STREQUAL "LINK")
  endforeach(_ARG)

  add_library(${plugin_name} SHARED ${_SOURCE_FILES})

  set_target_properties(${plugin_name} PROPERTIES
    PREFIX ""
    SUFFIX ".pso"
  )

  target_link_libraries(${plugin_name} ${_LINK_LIBS} dl)
endmacro(ADD_LIFTRACC_PLUGIN plugin_name)

#####
# compile plugins, too
#
add_subdirectory(${PROJECT_SOURCE_DIR}/src/plugins ${PROJECT_BINARY_DIR}/plugins)

#####
# compile tests
#
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

#####
# compile tune apps
#
add_subdirectory(${PROJECT_SOURCE_DIR}/tune)

#####
# generate documentation
#
add_custom_target(doc
  COMMENT "Generate documentation"
  COMMAND doxygen
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

