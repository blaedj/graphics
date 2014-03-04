#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Vector3D.h"
#include "shape.h"

namespace raytracer {
  class Sphere : public Shape {

  public:
    Sphere() {}
    virtual ~Sphere(){}

    Sphere(Vector3D center, double radius);

    Sphere(Vector3D center, double radius, Shader *shader);

    virtual HitInfo closestHit(const Ray &ray);

  private:
    Shader *shader;
    Vector3D center;
    double radius;


  };

}
#endif /* _SPHERE_H_ */
