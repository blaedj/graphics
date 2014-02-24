#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cassert>

#include "Vector3D.h"
#include "XMLSceneParser.h"
#include "handleGraphicsArgs.h"

namespace raytracer {
  class CameraCreator : public SceneElementCreator
  {
  public:
    CameraCreator() {}
    ~CameraCreator() {}

    void instance( ptree::value_type const &v )
    {
      std::istringstream buf;

      std::string name, type;
      Vector3D position, viewDir, lookatPoint;
      bool lookatSet = false;
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

      std::cout << "Camera: name=" << name << ", type=" << type << std::endl;
      std::cout << "\tposition: " << position << std::endl;
      if (lookatSet)
	std::cout << "\tlook at point: " << lookatPoint << std::endl;
      else
	std::cout << "\tview direction: " << viewDir << std::endl;
      std::cout << "\tfocal length: " << focalLength << std::endl;
      std::cout << "\timage plane width: " << imagePlaneWidth << std::endl;
    }

  private:
  };



}
