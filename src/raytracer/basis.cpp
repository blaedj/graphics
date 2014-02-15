#include "basis.h"

namespace raytracer{

  Basis::Basis() {
    U = Vector3D();
    V = Vector3D();
    W = Vector3D();
  };
  Basis::Basis(Vector3D& uVec, Vector3D& vVec, Vector3D& wVec){U=uVec; V=vVec; W=wVec;}
  Basis::~Basis() { };

}
