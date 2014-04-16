#ifndef __TERRAIN_GL_VIEW_H__
#define __TERRAIN_GL_VIEW_H__

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <limits>
#include <algorithm>
#include <stack>
#include <vector>

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "../../../raytracer/box.h"
#include "../../../raytracer/shader.h"

using namespace std;
using namespace raytracer;

class OpenGLRender
{
public:

  OpenGLRender(const int winWidth, const int winHeight);
  ~OpenGLRender() {}

  void run();

private:

  int m_winWidth, m_winHeight;
  sf::Window *m_Window;

  // Vertex Buffer Object related variables
  int m_numVertices;
  GLuint m_triangleVBO;
};

#endif
