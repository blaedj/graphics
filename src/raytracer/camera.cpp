#include "camera.h"

using namespace std;

namespace raytracer {

  Camera::Camera(void){
    location = Vector3D(1.0, 1.0, 1.0);
    viewDirection = Vector3D(0.0,0.0,-1.0);
    this->orthoBasis = Basis();
    this->imageHeight = 100.0;
    this->imageWidth = 100.0;
  }

  Camera::Camera(Vector3D location, std::string name, float focalLength, float imagePlaneWidth){
    this->location = location;
    this->name = name;
    this->focalLength = focalLength;
    this->imagePlaneWidth = imagePlaneWidth;

    // construct a basis from a single vector
    Vector3D W(location[0], location[1], location[2]); // create a copy of the location vector to normalize.
    W.normalize();
    Vector3D U = getNonColinear(W);
    Vector3D V = W*U;
    viewDirection = Vector3D(0.0,0.0,-1.0);
    orthoBasis = Basis(U, V, W);
    this->imageHeight = 100.0;
    this->imageWidth = 100.0;
  }

  Camera::Camera(Vector3D location, Vector3D direction, std::string name, float focalLength, float imagePlaneWidth){
    this->location = location;
    this->viewDirection = direction;
    this->name = name;
    this->focalLength = focalLength;
    this->imagePlaneWidth = imagePlaneWidth;
    // construct a basis from 2 vectors
    Vector3D W(direction);
    W.normalize();
    Vector3D upDir(0.0, 1.0, 0.0);

    if(areColinear(W, upDir)) {
      cout << "were colinear, corected\n";
      upDir.set(0.0, 1.1, 0.0);
      upDir.normalize();
    }

    Vector3D U = upDir.cross(W);
    U.normalize();
    Vector3D V = W.cross(U);

    orthoBasis = Basis(U, V, W);
    this->imageHeight = 100.0;
    this->imageWidth = 100.0;
  }

  bool Camera::areColinear(Vector3D& a, Vector3D& b) {
    //test for co-linearity: (u dot v) / (length(u) * length(v)) > 1 - epsilon
    double eps = .0001;
    return ((a.dot(b) / a.length() * b.length()) > (1.0 -eps));
  }

  Vector3D Camera::getNonColinear(Vector3D vec) {
    Vector3D nonColinearVec(vec);

    if(vec[0] <= vec[1] && vec[0] <= vec[2]) {
      nonColinearVec.set(1.0, vec[1], vec[2]);
    } else if(vec[1] <= vec[0] && vec[1] <= vec[2]) {
      nonColinearVec.set(vec[0], 1.0, vec[2]);
    } else if(vec[2] <= vec[1] && vec[2] <= vec[1]) {
      nonColinearVec.set(vec[0], vec[1], 1.0);
    }
    return nonColinearVec;
  }

}
