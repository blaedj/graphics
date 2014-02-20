
#include <iostream>
#include "basis.h"

using namespace std;


namespace raytracer{

  Basis::Basis() {
    U = Vector3D(1.0,0.0,0.0);
    V = Vector3D(0.0,1.0,0.0);
    W = Vector3D(0.0,0.0,1.0);
    cout << "u,v,w for basis: \n";
    cout << U << endl;
    cout << V << endl;
    cout << W << endl;
  };
  Basis::Basis(Vector3D& uVec, Vector3D& vVec, Vector3D& wVec){U=uVec; V=vVec; W=wVec;}
  Basis::~Basis() { };

}
