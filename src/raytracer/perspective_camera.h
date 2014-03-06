#ifndef __RAYTRACER_PERSPECTIVE_CAMERA_H_
#define __RAYTRACER_PERSPECTIVE_CAMERA_H_

#include "basis.h"
#include "Vector3D.h"
#include "camera.h"
#include "ray.h"

using namespace sivelab;

namespace raytracer {

  class PerspectiveCamera : public Camera
  {
  public:

    //! Default constructor
    PerspectiveCamera();

    //! Constructor from only the location.
    PerspectiveCamera(Vector3D location, std::string name, float focalLength,
		      float imagePlaneWidth);

    //! Constructor from camera location and direction.
    PerspectiveCamera(Vector3D location, Vector3D direction, std::string name,
		      float focalLength, float imagePlaneWidth);

    virtual ~PerspectiveCamera();

    Ray computeRay(int i, int j, Ray &r);

    void setHeightWidth(float height, int width){
      this->imageHeight = height; this->imageWidth = width;
    }

  private:

  };
}


#endif /* _PERSPECTIVE_CAMERA_H_ */
