#ifndef _SCENE_CONTAINER_H_
#define _SCENE_CONTAINER_H_

#include <iostream>
#include <cstdlib>

class SceneContainer
{
public:
  SceneContainer();
  virtual ~SceneContainer();

  std::vector<Camera*> cameraList(10, Camera*());
  std::vector<Shape*> shapeList(10, Shape*());


};


#endif /* _SCENE_CONTAINER_H_ */
