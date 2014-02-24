#ifndef _SCENE_CONTAINER_CREATOR_H_
#define _SCENE_CONTAINER_CREATOR_H_

#include <iostream>
#include <cstdlib>

class SceneContainerCreator : public SceneElementCreator
{
public:
  SceneContainerCreator();
  virtual ~SceneContainerCreator();

  std::vector<Camera*> cameraList(10, Camera*());
  std::vector<Shape*> shapeList(10, Shape*());
  //std::vector<Shader*> shaderList(10, Shader*());

  void instance( ptree::value_type const &v){
    if(v.first == "sceneParamets"){
      //bool useEnvMap = false; // what is this for?
      Vector3D bg_color;
      string envmapPrefix;

      b;//TODO: finish the scene parser! also add a method to get back a scene object

    }

  }

};


#endif /* _SCENE_CONTAINER_CREATOR_H_ */
