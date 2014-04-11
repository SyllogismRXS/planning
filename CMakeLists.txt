cmake_minimum_required (VERSION 2.6)
project (plan)

set(PLAN_VERSION_MAJOR "0")
set(PLAN_VERSION_MINOR "0")
set(PLAN_VERSION_PATCH "0")
set(PLAN_VERSION "${PLAN_VERSION_MAJOR}.${PLAN_VERSION_MINOR}.${PLAN_VERSION_PATCH}")
set(PLAN_VERSION_DATE "2012.12.30")

# give PLAN 1 series a few more soversions
set(PLAN_SOVERSION "00")

set(CMAKE_INSTALL_PREFIX /usr/local)

# fetch all the local directories for generated code
get_filename_component(PLAN_LIB_DIR ./lib ABSOLUTE)
get_filename_component(PLAN_BIN_DIR ./bin ABSOLUTE)
get_filename_component(PLAN_INC_DIR ./include ABSOLUTE)
get_filename_component(PLAN_SRC_DIR ./src ABSOLUTE)
get_filename_component(PLAN_SHARE_DIR ./share ABSOLUTE)
get_filename_component(PLAN_BUILD_DIR ./build ABSOLUTE)
get_filename_component(PLAN_SCRIPTS_DIR ./scripts ABSOLUTE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall") # -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall") # -fprofile-arcs -ftest-coverage")

set(EXECUTABLE_OUTPUT_PATH ${PLAN_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PLAN_LIB_DIR})

## set the cmake defaults for libraries and binaries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PLAN_LIB_DIR} CACHE PATH 
  "Output directory for the dynamic libraries" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PLAN_BIN_DIR} CACHE PATH
  "Output directory for the binaries" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PLAN_LIB_DIR} CACHE PATH 
  "Output directory for the static libraries (archives)" )

###############################################################################
# Find LEMON
###############################################################################
## The next part looks for LEMON. Typically, you don't want to modify it.
##
## First, it tries to use LEMON as a CMAKE subproject by looking for
## it in the 'lemon' or 'deps/lemon' subdirectories or in directory
## given by the LEMON_SOURCE_ROOT_DIR variable.
## If LEMON isn't there, then CMAKE will try to find an installed
## version of LEMON. If it is installed at some non-standard place,
## then you must tell its location in the LEMON_ROOT_DIR CMAKE config
## variable. (Do not hard code it into your config! Others may keep
## LEMON at different places.)
#set(LEMON_SOURCE_ROOT_DIR "CMAKE_SOURCE_DIR/third-party-build/lemon-1.3")

FIND_PATH(LEMON_SOURCE_ROOT_DIR CMakeLists.txt
  PATHS ${CMAKE_SOURCE_DIR}/lemon ${CMAKE_SOURCE_DIR}/deps/lemon
  NO_DEFAULT_PATH
  DOC "Location of LEMON source as a CMAKE subproject")

IF(EXISTS ${LEMON_SOURCE_ROOT_DIR})
  ADD_SUBDIRECTORY(${LEMON_SOURCE_ROOT_DIR} deps/lemon)
  SET(LEMON_INCLUDE_DIRS
    ${LEMON_SOURCE_ROOT_DIR}
    ${CMAKE_BINARY_DIR}/deps/lemon
  )
  SET(LEMON_LIBRARIES lemon)
  UNSET(LEMON_ROOT_DIR CACHE)
  UNSET(LEMON_DIR CACHE)
  UNSET(LEMON_INCLUDE_DIR CACHE)
  UNSET(LEMON_LIBRARY CACHE)
ELSE()
  FIND_PACKAGE(LEMON QUIET NO_MODULE)
  FIND_PACKAGE(LEMON REQUIRED)
ENDIF()

INCLUDE_DIRECTORIES(
  ${LEMON_INCLUDE_DIRS}
)



INSTALL(DIRECTORY ${PLAN_INC_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING REGEX .*\\.h|.*\\.proto
)

#INSTALL(TARGETS ${} 
#  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#)

install(DIRECTORY ${PLAN_LIB_DIR}/ 
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  )

## let cmake know where the headers are
include_directories(${PLAN_INC_DIR})

## copy to plan/include
file(GLOB_RECURSE INCLUDE_FILES RELATIVE ${PLAN_SRC_DIR} src/*.h)
foreach(I ${INCLUDE_FILES})
  configure_file(${PLAN_SRC_DIR}/${I} ${PLAN_INC_DIR}/plan/${I} @ONLY)
endforeach()

add_subdirectory(src)
