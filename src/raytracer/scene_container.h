#ifndef _SCENE_CONTAINER_H_
#define _SCENE_CONTAINER_H_

#include <iostream>
#include <cstdlib>

//TODO: this class should support the concept of anyHit and closestHit
// anyhit may or may not require tmax & tmin
// tmin: should be small but not zero. maybe 10 x e^-4
// for float: 10 x e^-7 is the machine epsilon

class SceneContainer
{
public:
  SceneContainer();
  virtual ~SceneContainer();

  std::vector<Camera*> cameraList(10, Camera*());
  std::vector<Shape*> shapeList(10, Shape*());

  //TODO: public Vector3D rayColor(Ray r, ) { // returns a color vector. inteface to all primary and reflective array for color computaion.
  // find closest object
  // apply_shader()
  // return color;
  // }
};


#endif /* _SCENE_CONTAINER_H_ */
