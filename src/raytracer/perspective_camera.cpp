#include "perspective_camera.h"

using namespace std;

namespace raytracer {

  PerspectiveCamera::~PerspectiveCamera(){}

  PerspectiveCamera::PerspectiveCamera() {}

  PerspectiveCamera::PerspectiveCamera(Vector3D location,std::string name, float focalLength, float imagePlaneWidth) : Camera(location, name, focalLength, imagePlaneWidth){ }

  PerspectiveCamera::PerspectiveCamera(Vector3D location, Vector3D direction, std::string name, float focalLength, float imagePlaneWidth) :
    Camera(location, direction, name, focalLength, imagePlaneWidth){ }

  Ray PerspectiveCamera::computeRay(int i, int j){
    float leftBound = -(imageWidth/2.0);
    float rightBound = (imageWidth/2.0);
    float bottomBound = -(imageHeight/2.0);
    float topBound = (imageHeight/2.0);

    double rayU = leftBound + (rightBound - leftBound)*(i + 0.5) / imageWidth;
    double rayV = bottomBound + (topBound - bottomBound)*(j + 0.5) / imageHeight;

    //	 ray.direction = -d*W + u*U + v*V
    // ray.origin = e;// e => camera origin
    const Vector3D rayDirection = ((-1.0 ) * this->focalLength) *
      (this->orthoBasis.W) + (rayU * this->orthoBasis.U) +
      (rayV * this->orthoBasis.V);

    const Vector3D rayOrigin = this->location;
    Ray ray(rayOrigin, rayDirection);
    return ray;
  }

}
