#include "cube.h"

using namespace sivelab;


Cube::render(){
  glClear();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt( 0, 0, 5, 0, 0, 0, 0, 1, 0 );

}
