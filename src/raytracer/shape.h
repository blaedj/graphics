#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <cstdlib>

#include "ray.h"
#include "shader.h"
#include "basis.h"


namespace raytracer {

  struct HitInfo;

  class Shape
  {
  public:
    Shape() {}
    virtual ~Shape() {}

    virtual HitInfo closestHit(const Ray &ray, float tmin, float &tmax) = 0;
    virtual Vector3D applyShader() = 0;
    virtual Vector3D normalAtPoint(Vector3D point) = 0;
    //virtual Vector3D getCenter() = 0;
    Basis ortho;
    Vector3D middleCenter;
    string name;
    Shader* getShader() { return this->shader;}

  protected:
    Shader* shader;

  };

  struct HitInfo
  {
    bool hit;
    float distance;
    Vector3D surfaceNormal;
    Shader *shader;
    Shape *hitShape;
  };


}

#endif /* _SHAPE_H_ */
