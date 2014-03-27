#include <cfloat>

#include "scene.h"

using namespace std;
using namespace sivelab;

namespace raytracer {

  bool hitStructValid(HitInfo hitStruct, float tmin, float &tmax);

  void Scene::instance(const ptree::value_type &v) {

    if (v.first == "sceneParameters") {
      //bool useEnvMap = false; // what is this for?
      // Vector3D bg_color;
      // string envmapPrefix;

      // //TODO: Actually use these maybe?
      // boost::optional<std::string> pBGColor = v.second.get_optional<
      // 	std::string>("bgColor");
      // boost::optional<std::string> pEnvMapPrefix = v.second.get_optional<
      // 	std::string>("envMapPrefix");
    }

    if (v.first == "light") {
      std::string type;
      sivelab::Vector3D position, intensity;
      std::istringstream buf;
      Light *light;
      type = v.second.get<std::string>("<xmlattr>.type");

      buf.str(v.second.get<std::string>("position"));
      buf >> position;
      buf.clear();

      buf.str(v.second.get<std::string>("intensity"));
      buf >> intensity;
      buf.clear();

      if (type == "point") {

	// Instance the new Point light...
	light = new Light(intensity, position);
	lightList.push_back(light);
      }
    }

    // Shader
    if (v.first == "shader") {
      //string name = v.second.get<std::string>("<xmlattr>.name");
      parseShaderData(v);
      // allShaders.insert(std::pair<string, Shader*>(name, sh));
      // need mirror, lambertion and blinn-phong shaders
      //std::map<string, shader*> shaderMap;
      //for each shader, map the shader name to a pointer to a shader
    }

    // Shape or Instance
    if (v.first == "shape") {
      // Shape *s = parseShapeData(v);
      // cout << "the shape name is:\n";
      // cout << s->name << endl;
      // shapeList.push_back(s);
      parseShapeData(v);
    }

    if (v.first == "camera") {
      this->cameraList.push_back(parseCameraData(v));
    }
  }

  void Scene::parseShapeData(ptree::value_type const &v) {
    //	  v.second.get < std::string > ("intensity")
    std::istringstream buffer;
    Shape *s;
    string type, name, shaderName;
    Shader *shadr;
    type = v.second.get<std::string>("<xmlattr>.type");
    name = v.second.get<std::string>("<xmlattr>.name");

    ptree::const_assoc_iterator it;
    it = v.second.find("shader");
    if( it != v.second.not_found() )
      {
    	shaderName = (*it).second.get<std::string>("<xmlattr>.ref");
      } else {;/*cout << "shader not found\n";*/}

    std::map<string, Shader*>::iterator iter;
    iter = allShaders.find(shaderName);
    shadr = iter->second;

    if (type == "sphere") {
      float radius;
      Vector3D center;
      buffer.str(v.second.get<string>("center"));
      buffer >> center; // Vector3D has overloaded <<
      buffer.clear();
      radius = v.second.get<float>("radius");
      s = new Sphere(center, radius, shadr);
      //}
      shapeList.push_back(s);
      //return s;
    } else if(type == "triangle") {
      Vector3D v0, v1, v2;
      buffer.str(v.second.get<string>("v0"));
      buffer >> v0;
      buffer.clear();

      buffer.str(v.second.get<string>("v1"));
      buffer >> v1;
      buffer.clear();

      buffer.str(v.second.get<string>("v2"));
      buffer >> v2;
      buffer.clear();
      s = new Triangle(v0, v1, v2, shadr);
      shapeList.push_back(s);
    } else {
      s = new Sphere(Vector3D(0,0,0), 0.0);
      shapeList.push_back(s);
      cout << "unkown shape type\n";
      // Vector3D center(0.0,0.0,0.0);
      // Shape *s = new Sphere(center, 0.1);
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

    buf.str(v.second.get<std::string>("position"));
    buf >> position;
    buf.clear();

    // LookAtPoint and ViewDir are optional, but one should be specified.
    boost::optional<std::string> plookatPoint =
      v.second.get_optional<std::string>("lookatPoint");
    boost::optional<std::string> pviewDir =
      v.second.get_optional<std::string>("viewDir");

    if (plookatPoint) {
      lookatSet = true;
      buf.str(*plookatPoint);
      buf >> lookatPoint;
      buf.clear();
      //gaze = lookatPoint - camera.position).normalize();
      viewDir = lookatPoint - position;
      viewDir.normalize();
    } else if (pviewDir) {
      buf.str(*pviewDir);
      buf >> viewDir;
      buf.clear();
    }

    buf.str(v.second.get<std::string>("focalLength"));
    buf >> focalLength;
    buf.clear();

    buf.str(v.second.get<std::string>("imagePlaneWidth"));
    buf >> imagePlaneWidth;
    buf.clear();

    Camera *cam = new PerspectiveCamera(position, viewDir, name, focalLength,
					imagePlaneWidth);
    return cam;

  }

  void Scene::parseShaderData(const ptree::value_type &v) {
    Shader* shader;
    std::istringstream buffer;
    std::string type, name;
    boost::optional<std::string> optShaderRef =
      v.second.get_optional<std::string>("<xmlattr>.ref");
    type = v.second.get<std::string>("<xmlattr>.type");
    name = v.second.get<std::string>("<xmlattr>.name");

    //if(!optShaderRef) {// did no find the shader,create a new one.
    if (type == "Lambertian") {
      shader = new LambertianShader();
      sivelab::Vector3D kd;
      buffer.str( v.second.get<std::string>("diffuse") );
      buffer >> kd;
      buffer.clear();
      shader->setColor(kd);

      allShaders.insert(std::pair<string, Shader*>(name, shader));
      // } else{
      // 	cout << "Shader reference already loaded.\n";
      // }
    } else if(type == "BlinnPhong") {
      Vector3D diffuse, specular;
      float phongExp;

      buffer.str( v.second.get<std::string>("diffuse") );
      buffer >> diffuse;
      buffer.clear();

      buffer.str( v.second.get<std::string>("specular") );
      buffer >> specular;
      buffer.clear();

      phongExp = v.second.get<float>("phongExp");
      shader = new BlinnPhong(diffuse, specular, phongExp, 0.0);
      allShaders.insert(std::pair<string, Shader*>(name, shader));
    }else {
      shader = new LambertianShader();
      sivelab::Vector3D kd;
      buffer.str( v.second.get<std::string>("diffuse") );
      buffer >> kd;
      buffer.clear();
      shader->setColor(kd);

      allShaders.insert(std::pair<string, Shader*>(name, shader));
    }
  }




} /** end  raytracer*/
