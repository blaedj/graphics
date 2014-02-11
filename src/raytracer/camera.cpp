#include "camera.h"

using namespace std;

namespace raytracer {

  Camera::Camera() {}
  Camera::~Camera() {}

  Camera::Camera(Vector3D location){
    // construct a basis from a single vector
    // W = location.normalize()
    Vector3D W = location;
    W.normalize();
    Vector3D U = getNonColinear(W);
    Vector3D V = W*U;
    orthonormal = Basis(U, V, W);
  }

  Vector3D Camera::getNonColinear(Vector3D vector) {
    Vector3D nonColinearVec(vector);

    if(vector[0] <= vector[1] && vector[0] <= vector[2]) {
      nonColinearVec.set(1.0, vector[1], vector[2]);
    } else if(vector[1] <= vector[0] && vector[1] <= vector[2]) {
      nonColinearVec.set(vector[0], 1.0, vector[2]);
    } else if(vector[2] <= vector[1] && vector[2] <= vector[1]) {
      nonColinearVec.set(vector[0], vector[1], 1.0);
    }
    return nonColinearVec;
  }

  bool Camera::CameraIsValid() {
    return true;
  }

}
