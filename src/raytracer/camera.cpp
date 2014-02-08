#include "camera.h"

namespace raytracer {

  Camera::Camera() {}
  Camera::~Camera() {}

  Camera::Camera(Basis basis){
    orthonormal = basis;
  }

  bool Camera::CameraIsValid() {
    return true;
  }

}
