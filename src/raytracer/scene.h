#ifndef _SCENE_H_
#define _SCENE_H_





#include <iostream>
#include <cstdlib>

#include "camera.h"
#include "light.h"
#include "shape.h"
#include "basis.h"
#include "shader.h"
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include "SceneDataContainer.h"
#include "png++/png.hpp"

using namespace std;
using namespace sivelab;
using boost::property_tree::ptree;

namespace raytracer {

  class Scene : public SceneElementCreator {
  public:
    Scene() {}
    virtual ~Scene(){}

    std::vector<Camera*> cameraList;
    std::vector<Shape*> shapeList;
    //std::vector<Shader*> shaderList(10, Shader*());
    std::vector<Light*> lightList;

    void instance(ptree::value_type const &v);

    Shape* parseShapeData(ptree::value_type const &v);

    Camera* parseCameraData(const ptree::value_type &v);

    void render(std::string outFileName, int width, int height );

    Vector3D computeRayColor(Ray &ray, float tmin, float &tmax);

  };
}

#endif /* _SCENE_H_ */
