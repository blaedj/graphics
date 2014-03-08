#include <cfloat>

#include "scene.h"

using namespace std;
using namespace sivelab;

namespace raytracer {

  bool hitStructValid(HitInfo hitStruct, float tmin, float &tmax);
  void print_tree(const ptree& pt, int level);

  void Scene::instance(const ptree::value_type &v) {

    if (v.first == "sceneParameters") {
      //bool useEnvMap = false; // what is this for?
      Vector3D bg_color;
      string envmapPrefix;

      //TODO: Actually use these maybe?
      boost::optional<std::string> pBGColor = v.second.get_optional<
	std::string>("bgColor");
      boost::optional<std::string> pEnvMapPrefix = v.second.get_optional<
	std::string>("envMapPrefix");
    }

    if (v.first == "light") {
      std::string type;
      sivelab::Vector3D position, intensity;
      std::istringstream buf;

      type = v.second.get<std::string>("<xmlattr>.type");

      buf.str(v.second.get<std::string>("position"));
      buf >> position;
      buf.clear();

      buf.str(v.second.get<std::string>("intensity"));
      buf >> intensity;
      buf.clear();

      if (type == "point") {
	// Instance the new Point light...
	//std::cout << "Found a point light..." << std::endl;
	lightList.push_back(new Light());
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


  //  void print_tree(const ptree& pt, int level)
  //  {
  //    const std::string sep(2 * level, ' ');
  //    BOOST_FOREACH(const ptree::value_type &v, pt) {
  //      std::cout
  //	<< sep
  //	<< q(v.first) << " : " << q(v.second.data()) << "\n";
  //      print_tree(v.second, level + 1);
  //    }
  //  }

  void Scene::parseShapeData(ptree::value_type const &v) {
    //	  v.second.get < std::string > ("intensity")
    std::istringstream buffer;
    Shape *s;
    string type, name, shaderName;
    Shader *shadr;
    type = v.second.get<std::string>("<xmlattr>.type");
    name = v.second.get<std::string>("<xmlattr>.name");

    ptree::const_assoc_iterator it;
    cout << "looking for shader\n";
    it = v.second.find("shader");
    if( it != v.second.not_found() )
      {
    	shaderName = (*it).second.get<std::string>("<xmlattr>.ref");
      } else {cout << "shader not found\n";}

    std::map<string, Shader*>::iterator iter;
    cout << "looking in allShaders\n";
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
      // cout << "unkown shape type\n";
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
    boost::optional<std::string> plookatPoint = v.second.get_optional<
      std::string>("lookatPoint");
    boost::optional<std::string> pviewDir = v.second.get_optional<std::string>(
									       "viewDir");

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
    }
  }

  void Scene::render(std::string outFileName, int width, int height) {
    png::image<png::rgb_pixel> imageData(width, height);
    Vector3D color;
    Ray r;
    float tmin, tmax;
    tmin = 1.0;    //TODO: what should min be?
    tmax = FLT_MAX;

    Camera *selectedCamera = this->cameraList.at(0);
    /**HACK***/
    selectedCamera->imageWidth = width;
    selectedCamera->imageHeight = height;
    /**END HACK***/

    for (size_t y = 0; y < imageData.get_height(); ++y) {
      for (size_t x = 0; x < imageData.get_width(); ++x) {
	//assert((y >= 0) && (y < height) && x >= 0 && x < width);
	r = selectedCamera->computeRay(x, y, r);
	color = computeRayColor(r, tmin, tmax);
	imageData[y][x] = png::rgb_pixel(color[0] * 255.0, color[1] * 255.0,
					 color[2] * 255.0);
      }
    }
    imageData.write(outFileName);
  }



  // find closest object
  // apply_shader()
  // return color;
  Vector3D Scene::computeRayColor(Ray &ray, float tmin, float &tmax) {
    Shape *nearestShape;
    float marginError = .001f;
    float smallestDist = 50000.0;
    Shape *currShape;
    Vector3D tempColor(0.0, 0.0, 0.0);
    /*********************************/
    struct HitInfo hitStruct;
    /** TOBE REPLACED BY BVH**/
    for (int i = 0; i < this->shapeList.size(); i++) {
      currShape = this->shapeList[i];
      hitStruct = currShape->closestHit(ray, tmin, tmax);
      if (hitStruct.hit && hitStruct.distance <= smallestDist ) {
	Shader *sh = hitStruct.shader;
	tempColor = sh->getColor();
	smallestDist = hitStruct.distance;
      } else {
	//tempColor.set(0.0, 0.0, 0.0);
      }
    }
    /********/

    return tempColor;
  }



} /** end  raytracer*/
