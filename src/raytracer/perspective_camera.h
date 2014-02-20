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
    PerspectiveCamera(Vector3D location);

    //! Constructor from camera location and direction.
    PerspectiveCamera(Vector3D location, Vector3D direction);

    virtual ~PerspectiveCamera();

    Ray computeRay(int i, int j);

    void setHeightWidth(float height, int width){this->imageHeight = height; this->imageWidth = width;}


  private:
    float imageWidth;
    float imageHeight;
  };
}


#endif /* _PERSPECTIVE_CAMERA_H_ */
