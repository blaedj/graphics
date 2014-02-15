#ifndef __RAYTRACER_CAMERA_H_
#define __RAYTRACER_CAMERA_H_

#include "basis.h"
#include "Vector3D.h"

#include "ray.h"

using namespace sivelab;

namespace raytracer {
  class Camera
  {
  public:
    //! Default Constructor
    Camera() {};

    //! Constructor from only the location.
    Camera(Vector3D location) {};

    //! Constructor from camera location and direction.
    Camera(Vector3D location, Vector3D direction) {};

    virtual ~Camera() {}

    Ray computeRay(int i, int j){};

    Basis camerasOrigin;
    Vector3D location;
    Vector3D viewDirection;
    float focalLength;
    float imagePlaneWidth;
    Basis orthoBasis;

  private:

  };
}

#endif /* _CAMERA_H_ */
