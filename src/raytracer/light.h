#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "basis.h"
#include "Vector3D.h"

namespace raytracer {

  class Light
  {
  public:
    Light() {};
    Light(Vector3D intensity, Vector3D position) {
      this->intensity = intensity;
      this->position = position;
    }
    virtual ~Light() {};
    Basis orthonormal;


    Vector3D intensity;
    Vector3D position;


  };

}
#endif /* _LIGHT_H_ */
