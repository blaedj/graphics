#ifndef _CUBE_H_
#define _CUBE_H_

#include "Vector3D.h"
using namespace sivelab;

class Cube
{
public:
  Cube();
  virtual ~Cube();

  void render();

private:

  Vector3D minPoint;
  Vector3D maxPoint;

};

#endif /* _CUBE_H_ */
