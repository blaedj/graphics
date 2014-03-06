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
    Camera(void);

    //! Constructor from only the location.
    Camera(Vector3D location, std::string name, float focalLength, float imagePlaneWidth);

    //! Constructor from camera location and direction.
    Camera(Vector3D location, Vector3D direction, std::string name, float focalLength, float imagePlaneWidth);

    virtual ~Camera() {}

    virtual Ray computeRay(int i, int j, Ray &r) =0;// {}


    Vector3D location;
    Vector3D viewDirection;
    float focalLength;
    float imageWidth;
    float imageHeight;
    Basis orthoBasis;
    std::string name;
    float imagePlaneWidth;

  private:
    bool areColinear(Vector3D& a, Vector3D& b);

    Vector3D getNonColinear(Vector3D vec);

  };
}

#endif /* _CAMERA_H_ */
