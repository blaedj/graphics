#ifndef _RASTERIZER_H_
#define _RASTERIZER_H_


#include "Scene.h"
#include "handleGraphicsArgs.h"
#include "shape.h"
#include "triangle.h"
#include "camera.h"
#include "Matrix4x4.h"

using namespace sivelab;
using namespace raytracer;
using namespace std;

namespace rasterizer {
  const int VERTICES_PER_TRIANGLE = 3;

  class Rasterizer
  {
  public:
    Rasterizer();

    Rasterizer(raytracer::Scene *scene, GraphicsArgs args);

    virtual ~Rasterizer(){}

    void render();



  private:
    // should make this a vector of triangle pointers...
    std::vector<Triangle> m_triangles;//(10, Triangle());
    Camera *m_camera;
    int m_width;
    int m_height;
    string m_outputFileName;
    double m_focal_length;
    Matrix4x4 generateTransform();
  };

}


#endif /* _RASTERIZER_H_ */
