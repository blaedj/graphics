#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include "shader.h"
#include "solid_shader.h"

using namespace sivelab;

namespace raytracer {

  class Triangle : public Shape {

  public:
    Triangle(Vector3D vert1, Vector3D vert2, Vector3D vert3, Shader* shadr);
    Triangle() {}
    ~Triangle() {}

    virtual HitInfo closestHit(const Ray &ray, float tmin, float &tmax);
    virtual Vector3D applyShader();
    virtual Vector3D normalAtPoint(Vector3D point);

    const double operator[](const int i) const
    {
      // do a sanity check to make sure indices are OK!
      assert(i >= 0 && i < 9);
      return vertices[i];
    }

    double vertices[9];
  private:
    void setShader(Shader* sh);
    Vector3D p1;
    Vector3D p2;
    Vector3D p3;
    Vector3D normal;

  };
} /** end  raytracer*/


#endif /* _TRIANGLE_H_ */
