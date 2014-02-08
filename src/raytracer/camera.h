#ifndef __RAYTRACER_CAMERA_H_
#define __RAYTRACER_CAMERA_H_

#include "basis.h"

namespace raytracer {
  class Camera
  {
  public:
    Camera();
    Camera(Basis basis);
    virtual ~Camera();
    bool CameraIsValid();

  private:
    Basis orthonormal;


  };
}

#endif /* _CAMERA_H_ */
