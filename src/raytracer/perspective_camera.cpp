#include "perspective_camera.h"
#include "stdlib.h"
using namespace std;

namespace raytracer {

  PerspectiveCamera::~PerspectiveCamera(){}

  PerspectiveCamera::PerspectiveCamera() {}

  // default view dir
  PerspectiveCamera::PerspectiveCamera(Vector3D location,std::string name, float focalLength, float imagePlaneWidth) : Camera(location, name, focalLength, imagePlaneWidth){ }

  // supplied view dir
  PerspectiveCamera::PerspectiveCamera(Vector3D location, Vector3D direction, std::string name, float focalLength, float imagePlaneWidth) :
    Camera(location, direction, name, focalLength, imagePlaneWidth){ }

  Ray PerspectiveCamera::computeRay(int i, int j, Ray &r){
    Vector3D U = this->orthoBasis.U;
    Vector3D V = this->orthoBasis.V;
    Vector3D W = this->orthoBasis.W;

    float imagePlaneHeight = (this->imagePlaneWidth * imageHeight) / imageWidth;

    float u = -imagePlaneHeight + (imagePlaneHeight + imagePlaneHeight)
      * (i + 0.5) / imageHeight;

    float v = -this->imagePlaneWidth + (this->imagePlaneWidth + this->imagePlaneWidth)
      * (j + 0.5) / imageWidth;

    Vector3D rayDirection = -(this->focalLength)*W + u*U +v*V;
    rayDirection.normalize();
    r.origin = this->location;
    r.direction = rayDirection;
    return r;
  }

}
