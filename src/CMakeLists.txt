cmake_minimum_required (VERSION 2.8)
project(graphicsBCJ)

SET(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

# --------------------------------------------------------------------
# PNG and ZLIB
#
# This macro will attempt to locate the PNG include directories, link
# directories and libraries. The INCLUDE_DIRECTORIES macro adds the
# resulting include directories to the search path.
# --------------------------------------------------------------------
find_package(PNG REQUIRED)
if (PNG_FOUND)
  INCLUDE_DIRECTORIES(${PNG_INCLUDE_DIR})
else (PNG_FOUND)
  MESSAGE(STATUS "Could not find the PNG Libraries!")
endif (PNG_FOUND)

# --------------------------------------------------------------------
# SFML and OpenGL
#
# --------------------------------------------------------------------
FIND_PACKAGE(SFML 1 COMPONENTS system window graphics audio REQUIRED)
# FIND_LIBRARY(SFML-SYSTEM_LIBRARY NAMES sfml-system )
# FIND_LIBRARY(SFML-GRAPHICS_LIBRARY NAMES sfml-graphics )
# FIND_LIBRARY(SFML-WINDOW_LIBRARY NAMES sfml-window )


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


INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/raytracer)


INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/rasterizer)


ADD_SUBDIRECTORY(raytracer)
ADD_SUBDIRECTORY(rasterizer)
ADD_SUBDIRECTORY(petesCode/cs5721GraphicsLib/)

LINK_DIRECTORIES(${CMAKE_BUILD_DIR}/petesCode/cs5721GraphicsLib/src)
LINK_DIRECTORIES(${CMAKE_BUILD_DIR}/raytracer)
LINK_DIRECTORIES(${CMAKE_BUILD_DIR}/rasterizer)

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

add_executable(write_images
  main.cpp
  )

target_link_libraries(write_images raytracer)
target_link_libraries(write_images rasterizer)
target_link_libraries(write_images sive-rtutil)
target_link_libraries(write_images ${Boost_PROGRAM_OPTIONS_LIBRARIES})
target_link_libraries(write_images ${PNG_LIBRARY})
target_link_libraries(write_images ${ZLIB_LIBRARY})
