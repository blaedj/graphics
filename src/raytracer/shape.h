#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <cstdlib>

#include "ray.h"
#include "shader.h"
#include "basis.h"

namespace raytracer {
  class Shape
  {
  public:
    Shape();
    virtual ~Shape();
    virtual bool closesstHit(const Ray &ray);
    Basis ortho;
    Shader* shader;
    Vector3D center;
  };
}

#endif /* _SHAPE_H_ */
