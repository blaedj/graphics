#ifndef __RAYTRACER_CAMERA_H_
#define __RAYTRACER_CAMERA_H_

#include "basis.h"
#include "Vector3D.h"

using namespace sivelab;

namespace raytracer {
  class Camera
  {
  public:
    //! Default Constructor
    Camera();

    //! Constructor from only the location.
    Camera(Vector3D location);

    virtual ~Camera();

    bool CameraIsValid();
    Vector3D getNonColinear(Vector3D vector);

    Basis orthonormal;
    double aX;
    double aY;
    double aZ;

  private:

  };
}

#endif /* _CAMERA_H_ */
