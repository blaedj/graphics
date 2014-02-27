#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Vector3D.h"
#include "shape.h"

namespace raytracer {
  class Sphere : public Shape {

  public:
    Sphere();
    Sphere(Vector3D center, double radius);

    virtual ~Sphere();

    virtual bool closestHit(const Ray &ray, float &dist);

  private:
    Vector3D center;
    double radius;


  };

}
#endif /* _SPHERE_H_ */
