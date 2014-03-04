#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <cstdlib>

#include "ray.h"
#include "shader.h"
#include "basis.h"

namespace raytracer {
 struct HitInfo
 {
   bool hit;
   float distance;
   Vector3D surfaceNormal;
 };

  class Shape
  {
  public:
    Shape() {}
    virtual ~Shape() {}

    virtual HitInfo closestHit(const Ray &ray) = 0;
    Basis ortho;
    Shader* shader;
    Vector3D center;

  };
}

#endif /* _SHAPE_H_ */
