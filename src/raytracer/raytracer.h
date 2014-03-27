#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

#include <iostream>
#include <cstdlib>
#include <float.h>

#include "shape.h"
#include "scene.h"
#include "ray.h"
#include "handleGraphicsArgs.h"


using namespace sivelab;
using namespace std;

namespace raytracer {
  class Raytracer
  {
  public:
    Raytracer();
    virtual ~Raytracer();

    Raytracer(Scene scene, GraphicsArgs args);

    void render(std::string outFileName, int width, int height );

    Vector3D computeRayColor(Ray &ray, float tmin, float &tmax);

  private:
    HitInfo getNearestHit(float tmin, Ray& ray, float& tmax);
    bool anyHit(float tmin, Ray& ray, float& tmax);
    Scene scene;


  };
} /** end  raytracer*/
#endif /* _RAYTRACER_H_ */
