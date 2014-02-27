#ifndef _SCENE_CONTAINER_CREATOR_H_
#define _SCENE_CONTAINER_CREATOR_H_

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

using namespace std;
using namespace sivelab;
using boost::property_tree::ptree;

namespace raytracer {


  class SceneContainerCreator : public SceneElementCreator {
  public:
    SceneContainerCreator();// {}
    virtual ~SceneContainerCreator();

    std::vector<Camera*> cameraList;
    std::vector<Shape*> shapeList;
    //std::vector<Shader*> shaderList(10, Shader*());
    std::vector<Light*> lightList;

    void instance(ptree::value_type const &v) {

      if (v.first == "sceneParameters") {
	//bool useEnvMap = false; // what is this for?
	Vector3D bg_color;
	string envmapPrefix;

	//TODO: Actually use these maybe?
	boost::optional<std::string> pBGColor = v.second.get_optional
	  < std::string > ("bgColor");
	boost::optional<std::string> pEnvMapPrefix = v.second.get_optional
	  < std::string > ("envMapPrefix");
      }

      if (v.first == "light") {
	std::string type;
	sivelab::Vector3D position, intensity;
	std::istringstream buf;

	type = v.second.get < std::string > ("<xmlattr>.type");

	buf.str(v.second.get < std::string > ("position"));
	buf >> position;
	buf.clear();

	buf.str(v.second.get < std::string > ("intensity"));
	buf >> intensity;
	buf.clear();

	if (type == "point") {
	  // Instance the new Point light...
	  std::cout << "Found a point light..." << std::endl;
	  lightList.push_back(new Light());
	}
      }

      // Shader
      if (v.first == "shader") {
	//parseShaderData(v );
	// need mirror, lambertion and blinn-phong shaders
      }

      // Shape or Instance
      if (v.first == "shape") {
	shapeList.push_back(parseShapeData(v));
      }
    }

    Shape* parseShapeData(ptree::value_type const &v);

  };
}
#endif /* _SCENE_CONTAINER_CREATOR_H_ */
