cmake_minimum_required (VERSION 2.8)
project(graphicsBCJ)

SET (Boost_MULTITHREADED TRUE)

# If you want to get more info on what the Find Boost macro is
# doing...
# SET(Boost_DEBUG 1)

# Necessary to get Win32 version to work, plus, not a bad idea to link
# statically for our purposes.
SET(Boost_USE_STATIC_LIBS TRUE)

FIND_PACKAGE(Boost REQUIRED date_time program_options system thread unit_test_framework)
IF(${Boost_FOUND})
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/petesCode/cs5721GraphicsLib/src)
LINK_DIRECTORIES(${CMAKE_BUILD_DIR}/petesCode/cs5721GraphicsLib/src)

ADD_SUBDIRECTORY(raytracer)
ADD_SUBDIRECTORY(petesCode/cs5721GraphicsLib/)