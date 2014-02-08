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

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/raytracer)
LINK_DIRECTORIES(${CMAKE_BUILD_DIR}/raytracer)

ADD_SUBDIRECTORY(raytracer)
ADD_SUBDIRECTORY(petesCode/cs5721GraphicsLib/)



#
# Unit Tests - by enabling testing with cmake, we can create a target
# that lets any of your unit tests be run when issuing a make command. After re-building your project with
# ENABLE_TESTING called, a make target, called 'test' will be enabled. You can then type
#
#  make test
#
# to perform the unit tests that you associate with the target. For more detail, see my
# CMakeLists.txt file in the utests directory of the cs5721GraphicsLib source
# for more details. Also, see the unit test .cpp files in the same utests directory for
# more examples on using Boost's unit test system.
#

ENABLE_TESTING()
ADD_SUBDIRECTORY(utests)