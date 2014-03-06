#ifndef _BASIS_H_
#define _BASIS_H_

#include "Vector3D.h"

using namespace sivelab;

namespace raytracer {
  /*
   * Orthonormal Basis
   */
  class Basis
  {
  public:
    //! Default constructor. Sets to (1,1,1)^3
    Basis();
    virtual ~Basis();

    Basis(Vector3D& uVec, Vector3D& vVec, Vector3D& wVec);

    void set(Vector3D uVec, Vector3D vVec, Vector3D wVec){U=uVec; V=vVec; W=wVec;}

    Vector3D U;
    Vector3D V;
    Vector3D W;
  };
}


#endif /* _BASIS_H_ */
