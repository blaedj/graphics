include_directories(${CMAKE_SOURCE_DIR}/src)

# FIND_PACKAGE(SFML 1 COMPONENTS system window graphics audio REQUIRED)
# FIND_LIBRARY(SFML-SYSTEM_LIBRARY NAMES sfml-system )
# FIND_LIBRARY(SFML-GRAPHICS_LIBRARY NAMES sfml-graphics )
# FIND_LIBRARY(SFML-WINDOW_LIBRARY NAMES sfml-window )

INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
link_libraries (${OPENGL_LIBRARY})

include_directories(${CMAKE_SOURCE_DIR}/petesCode/cs5721GraphicsLib/src)
link_directories(${CMAKE_BINARY_DIR}/petesCode/cs5721GraphicsLib/src)

add_executable (openGLRender
  OpenGLRender.h OpenGLRender.cpp
  simpleSFMLGL.cpp
  cube.cpp cube.h
)
target_link_libraries (openGLRender sive-rtutil)
target_link_libraries (openGLRender ${Boost_THREAD_LIBRARIES})
target_link_libraries (openGLRender ${Boost_PROGRAM_OPTIONS_LIBRARIES})
target_link_libraries (openGLRender ${Boost_FILESYSTEM_LIBRARIES})
target_link_libraries (openGLRender ${Boost_SYSTEM_LIBRARIES})
target_link_libraries (openGLRender ${SFML_LIBRARIES})
target_link_libraries (openGLRender GLEW)
#target_link_libraries (openGLRender png)
target_link_libraries (openGLRender z)


# add_executable (vboRender
#   vboExample.cpp
# )
# target_link_libraries (vboRender sive-rtutil)
# target_link_libraries (vboRender ${Boost_THREAD_LIBRARIES})
# target_link_libraries (vboRender ${Boost_PROGRAM_OPTIONS_LIBRARIES})
# target_link_libraries (vboRender ${Boost_FILESYSTEM_LIBRARIES})
# target_link_libraries (vboRender ${Boost_SYSTEM_LIBRARIES})
# target_link_libraries (vboRender ${SFML-GRAPHICS_LIBRARY})
# target_link_libraries (vboRender ${SFML-WINDOW_LIBRARY})
# target_link_libraries (vboRender ${SFML-SYSTEM_LIBRARY})
# target_link_libraries (vboRender ${GDAL_LIBRARY})
# target_link_libraries (vboRender GLEW)
# target_link_libraries (vboRender png)
# target_link_libraries (vboRender z)

# add_executable (fboExample
# 	       fboExample.cpp
# 	       framebufferObject.cpp framebufferObject.h
# 	       GLSL.cpp GLSL.h
# )
# target_link_libraries (fboExample sive-rtutil)
# target_link_libraries (fboExample ${Boost_THREAD_LIBRARIES})
# target_link_libraries (fboExample ${Boost_PROGRAM_OPTIONS_LIBRARIES})
# target_link_libraries (fboExample ${Boost_FILESYSTEM_LIBRARIES})
# target_link_libraries (fboExample ${Boost_SYSTEM_LIBRARIES})
# target_link_libraries (fboExample ${SFML_LIBRARIES})
# target_link_libraries (fboExample GLEW)
# target_link_libraries (fboExample png)
# target_link_libraries (fboExample z)
