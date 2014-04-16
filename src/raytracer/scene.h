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
#include "perspective_camera.h"
#include "lambertian_shader.h"
#include "sphere.h"
#include "triangle.h"
#include "box.h"
#include "blinn_phong.h"

using namespace std;
using namespace sivelab;
using boost::property_tree::ptree;

namespace raytracer {

  //TODO: this class should support the concept of anyHit and closestHit
  // anyhit may or may not require tmax & tmin
  // tmin: should be small but not zero. maybe 10 x e^-4
  // for float: 10 x e^-7 is the machine epsilon


  //TODO: public Vector3D rayColor(Ray r, ) { // returns a color vector. inteface to all primary and reflective array for color computaion.
  // find closest object
  // apply_shader()
  // return color;
  // }

  class Scene : public SceneElementCreator {
  public:
    Scene() {}
    virtual ~Scene() {}

    std::vector<Camera*> cameraList;
    std::vector<Shape*> shapeList;
    std::map<string, Shader*> allShaders;
    std::vector<Light*> lightList;

    void instance(ptree::value_type const &v);

    /* inserts into shapeList a shape constructed from parsed data.*/
    void parseShapeData(ptree::value_type const &v);

    Camera* parseCameraData( ptree::value_type const &v);

    void parseShaderData(ptree::value_type const &v);

    std::vector<Triangle> getTriangles(){
      return m_allTriangles;
    };

  private:
    std::vector<Triangle> m_allTriangles;

  };
}

#endif /* _SCENE_H_ */
