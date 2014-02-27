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
    Shape() {}
    virtual ~Shape() {}

    virtual bool closestHit(const Ray &ray, float &distance) = 0;
    Basis ortho;
    Shader* shader;
    Vector3D center;
  };
}

#endif /* _SHAPE_H_ */
