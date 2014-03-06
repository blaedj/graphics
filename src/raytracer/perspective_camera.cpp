#include "perspective_camera.h"
#include "stdlib.h"
using namespace std;

namespace raytracer {

  PerspectiveCamera::~PerspectiveCamera(){}

  PerspectiveCamera::PerspectiveCamera() {}

  PerspectiveCamera::PerspectiveCamera(Vector3D location,std::string name, float focalLength, float imagePlaneWidth) : Camera(location, name, focalLength, imagePlaneWidth){ }

  PerspectiveCamera::PerspectiveCamera(Vector3D location, Vector3D direction, std::string name, float focalLength, float imagePlaneWidth) :
    Camera(location, direction, name, focalLength, imagePlaneWidth){ }

  Ray PerspectiveCamera::computeRay(int i, int j, Ray &r){

    float leftBound = -(imageWidth/2.0);
    float rightBound = (imageWidth/2.0);
    float bottomBound = -(imageHeight/2.0);
    float topBound = (imageHeight/2.0);
    /*if(std::abs(leftBound) <= .001){
      cout << "An assertion has failed: abs(leftBound) < .001\n";
      cout << "image width: " << imageWidth << endl
      << "image height: " << imageWidth << endl
      << "i: " << "'" << i << "'" << endl
      << "j: " << "'" << j << "'" << endl;
      exit(EXIT_FAILURE);
      }
      if(std::abs(rightBound) < .001){
      cout << "An assertion has failed: abs(rightbound) < .001\n";
      cout << "image width: " << imageWidth << endl
      << "image height: " << imageWidth << endl
      << "i: " <<  i << endl
      << "j: " << j << endl;
      exit(EXIT_FAILURE);
      }
      if(std::abs(bottomBound) < .001) {
      cout << "An assertion has failed: abs(bottomBound) < .001\n";
      cout << "image width: " << imageWidth << endl
      << "image height: " << imageWidth << endl
      << "i: " <<  i << endl
      << "j: " << j << endl;
      exit(EXIT_FAILURE);
      } else {
      cout << "ok"
      << "image width: " << imageWidth << endl
      << "image height: " << imageWidth << endl
      << "i: " <<  i << endl
      << "j: " << j << endl;

      }

      if(std::abs(topBound) < .001){
      cout << "An assertion has failed: abs(topBound) < .001\n";
      cout << "image width: " << imageWidth << endl
      << "image height: " << imageWidth << endl
      << "i: " <<  i << endl
      << "j: " << j << endl;
      exit(EXIT_FAILURE);
      }*/
    double rayU = leftBound + (rightBound - leftBound)*(i + 0.5) / imageWidth;
    double rayV = bottomBound + (topBound - bottomBound)*(j + 0.5) / imageHeight;

    //	 ray.direction = -d*W + u*U + v*V
    // ray.origin = e; // e => camera origin
    Vector3D rayDirection = (-1.0 * this->focalLength)*(this->orthoBasis.W) +
      (rayU * this->orthoBasis.U) +
      (rayV * this->orthoBasis.V);
    rayDirection.normalize();
    const Vector3D rayOrigin = this->location;
    r.origin = rayOrigin;
    r.direction = rayDirection;
    return r;
  }

}
