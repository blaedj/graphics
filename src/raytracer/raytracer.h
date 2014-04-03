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
    virtual ~Raytracer(){}

    Raytracer(Scene *scene, GraphicsArgs args);

    void render();

    Vector3D computeRayColor(Ray &ray, float tmin, float &tmax);

  private:
    HitInfo getNearestHit(float tmin, Ray& ray, float& tmax);
    bool anyHit(float tmin, Ray& ray, float& tmax);
    Scene *scene;
    GraphicsArgs args;
    string outFileName;
    int height;
    int width;


  };
} /** end  raytracer*/
#endif /* _RAYTRACER_H_ */
