cmake_minimum_required (VERSION 2.8)
project(Rasterizer)

# --------------------------------------------------------------------
# PNG and ZLIB
#
# This macro will attempt to locate the PNG include directories, link
# directories and libraries. The INCLUDE_DIRECTORIES macro adds the
# resulting include directories to the search path.
# --------------------------------------------------------------------
find_package(PNG REQUIRED)

if (PNG_FOUND)
  MESSAGE(STATUS "Found png: ${PNG_INCLUDE_DIR}, ${PNG_LIBRARY}")
  INCLUDE_DIRECTORIES(${PNG_INCLUDE_DIR})
endif (PNG_FOUND)

# Boost -------
SET (Boost_MULTITHREADED TRUE)

# If you want to get more info on what the Find Boost macro does
# SET(Boost_DEBUG 1)

# Necessary to get Win32 version to work, plus, not a bad idea to link
# statically for our purposes.
SET(Boost_USE_STATIC_LIBS TRUE)

FIND_PACKAGE(Boost REQUIRED date_time program_options system thread unit_test_framework)
IF(${Boost_FOUND})
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

add_library(rasterizer
  rasterizer.cpp rasterizer.h
)

target_link_libraries(rasterizer ${Boost_PROGRAM_OPTIONS_LIBRARIES})
