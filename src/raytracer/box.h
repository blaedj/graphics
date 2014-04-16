#ifndef _BOX_H_
#define _BOX_H_


#include <vector>
#include <float.h>
#include "shader.h"
#include "shape.h"
#include "triangle.h"
#include "ray.h"

#include "solid_shader.h"

using namespace sivelab;
using namespace std;

namespace raytracer {

  class Box : public Shape {

  public:
    std::vector<Triangle> m_triangles;

    Box(Vector3D near, Vector3D far, Shader *sh);
    Box() {}
    ~Box(){}

    virtual HitInfo closestHit(const Ray &ray, float tmin, float &tmax);
    virtual Vector3D applyShader();
    virtual Vector3D normalAtPoint(Vector3D point);

    std::vector<Triangle> getTriangles() {
      return m_triangles;
    }
  private:

    void addTriangle(Vector3D a, Vector3D b, Vector3D c);
    Shader *m_sh;
    void setShader(Shader *sh);
  };


} /** end  raytracer*/

#endif /* _BOX_H_ */
