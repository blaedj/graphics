
#include "scene.h"
#include "sphere.h"

using namespace std;
using namespace sivelab;

namespace raytracer {

  void Scene::instance(const ptree::value_type &v) {

    if (v.first == "sceneParameters") {
      //bool useEnvMap = false; // what is this for?
      Vector3D bg_color;
      string envmapPrefix;

      //TODO: Actually use these maybe?
      boost::optional<std::string> pBGColor = v.second.get_optional< std::string > ("bgColor");
      boost::optional<std::string> pEnvMapPrefix = v.second.get_optional< std::string > ("envMapPrefix");
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
      //std::map<string, shader*> shaderMap;
      //for each shader, map the shader name to a pointer to a shader
    }

    // Shape or Instance
    if (v.first == "shape") {
      shapeList.push_back(parseShapeData(v));
    }

    if (v.first == "camera") {

      this->cameraList.push_back(parseCameraData(v));

    }

  }

  Shape* Scene::parseShapeData(const ptree::value_type &v) {
    //v.second.get < std::string > ("intensity")
    if(v.second.get<std::string>("type") == "sphere") {
      float radius;
      Vector3D position;
      Sphere *s = new Sphere();
    }
  }

  Camera* Scene::parseCameraData(const ptree::value_type &v) {
    std::istringstream buf;

    bool lookatSet = true;
    string name, type;
    Vector3D position, viewDir, lookatPoint;
    float focalLength;
    float imagePlaneWidth;

    name = v.second.get<std::string>("<xmlattr>.name");
    type = v.second.get<std::string>("<xmlattr>.type");

    buf.str( v.second.get<std::string>("position") );
    buf >> position;
    buf.clear();

    // LookAtPoint and ViewDir are optional, but one should be specified.
    boost::optional<std::string> plookatPoint = v.second.get_optional<std::string>("lookatPoint");
    boost::optional<std::string > pviewDir = v.second.get_optional<std::string>("viewDir");

    if (plookatPoint) {
      lookatSet = true;
      buf.str( *plookatPoint );
      buf >> lookatPoint;
      buf.clear();
      //gaze = lookatPoint - camera.position).normalize();
      viewDir = lookatPoint - position;
      viewDir.normalize();
    } else if (pviewDir) {
      buf.str( *pviewDir );
      buf >> viewDir;
      buf.clear();
    }

    buf.str( v.second.get<std::string>("focalLength") );
    buf >> focalLength;
    buf.clear();

    buf.str( v.second.get<std::string>("imagePlaneWidth") );
    buf >> imagePlaneWidth;
    buf.clear();

    Camera *cam = new Camera(position, viewDir, name, focalLength, imagePlaneWidth);
    return cam;

  }


} /** end  raytracer*/
