

#include "rasterizer.h"

namespace rasterizer {

  Rasterizer::Rasterizer(){}

  Rasterizer::Rasterizer(raytracer::Scene *scene, GraphicsArgs args){
    m_triangles = scene->getTriangles();
  }

  void Rasterizer::render() {
    //TODO: implement:
    //0) light and shade
    //1) local transforms on vertices -> world space
    //2) Clipping
    //3)

    for(int i = 0; < m_triangles.size(); i++){

    }

  }

} /** end  rasterizer*/
