#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "basis.h"

namespace raytracer {

  class Light
  {
  public:
    Light();
    virtual ~Light();
    Basis orthonormal;
  };

}
#endif /* _LIGHT_H_ */
