#ifndef _RASTERIZER_H_
#define _RASTERIZER_H_


#include "Scene.h"
#include "handleGraphicsArgs.h"

using namespace sivelab;
using namespace std;

namespace rasterizer {

  class Rasterizer
  {
  public:
    Rasterizer();

    Rasterizer(raytracer::Scene *scene, GraphicsArgs args);

    virtual ~Rasterizer(){}

    void render();


  };

}


#endif /* _RASTERIZER_H_ */
