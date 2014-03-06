#include <cfloat>

#include "scene.h"
#include "shape.h"
#include "sphere.h"

using namespace std;
using namespace sivelab;

namespace raytracer {

  bool hitStructValid(HitInfo hitStruct, float tmin, float &tmax);

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
      Shape *s = parseShapeData(v);

      shapeList.push_back(s);
    }

    if (v.first == "camera") {
      this->cameraList.push_back(parseCameraData(v));
    }

  }

  Shape* Scene::parseShapeData(ptree::value_type const &v) {
    //v.second.get < std::string > ("intensity")
    std::istringstream buffer;

    string type, name;
    type = v.second.get<std::string>("<xmlattr>.type");
    name = v.second.get<std::string>("<xmlattr>.name");

    if (type == "sphere") {
      float radius;
      Vector3D center;
      buffer.str(v.second.get<string>("center"));
      buffer >> center; // Vector3D has overloaded <<
      buffer.clear();

      cout << "Sphere's center is: " << center << endl;
      radius = v.second.get<float>("radius");

      Shape *s = new Sphere(center, radius);
      cout << "shape center and radius are" << s->getCenter() << " and "
	   << radius << endl;
      return s;
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

  void Scene::render(std::string outFileName, int width, int height) {
    // cout << "image rendered to " << outFileName << ".\n"
    // 	 << "with width " << width << " and height " << height << endl;

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

	//xassert((y >= 0) && (y < height) && x >= 0 && x < width);
	r = selectedCamera->computeRay(x, y, r);

	cout << "ray dir is:" << r.direction << endl;
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
    float marginError = .1f;
    float distance = 0.0;
    Shape *currShape;
    Vector3D tempColor(0.0, 0.0, 0.0);

    for (int i = 0; i < this->shapeList.size(); i++) {
      currShape = this->shapeList.at(i);

      struct HitInfo hitStruct = currShape->closestHit(ray, tmin, tmax);
      if (hitStruct.hit) {
	tempColor = hitStruct.shader->getColor();
	cout << "got a hit\n";
      }
    }
    return tempColor;
  }

} /** end  raytracer*/
