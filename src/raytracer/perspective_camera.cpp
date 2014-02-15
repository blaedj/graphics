#include "perspective_camera.h"

using namespace std;

bool areColinear(Vector3D a, Vector3D b);

namespace raytracer {

  PerspectiveCamera::~PerspectiveCamera(){}
  PerspectiveCamera::PerspectiveCamera() {
    location = Vector3D();
    viewDirection = Vector3D(0.0,0.0,-1.0);
  }

  PerspectiveCamera::PerspectiveCamera(sivelab::Vector3D location) {
    this->location = location;

    // construct a basis from a single vector
    Vector3D W(location[0], location[1], location[2]); // create a copy of the location vector to normalize.
    W.normalize();
    Vector3D U = getNonColinear(W);
    Vector3D V = W*U;
    viewDirection = Vector3D(0.0,0.0,-1.0);
    orthoBasis = Basis(U, V, W);
  }

  PerspectiveCamera::PerspectiveCamera(Vector3D location, Vector3D direction) {
    this->location = location;
    this->viewDirection = direction;

    // construct a basis from 2 vectors
    Vector3D W = direction;
    W.normalize();
    Vector3D upDir(0.0, 1.0, 0.0);

    if(areColinear(W, upDir)) {
      upDir.set(0.0, 1.1, 0.0);
      upDir.normalize();
    }

    Vector3D U = upDir.cross(W);
    U.normalize();
    Vector3D V = W.cross(U);

    orthoBasis = Basis(U, V, W);
  }

  bool PerspectiveCamera::areColinear(Vector3D a, Vector3D b) {
	 //test for co-linearity: (u dot v) / (length(u) * length(v)) > 1 - epsilon
     double eps = .0001;
     return ((a.dot(b) / a.length() * b.length()) > (1.0 -eps));
   }



  Ray PerspectiveCamera::computeRay(int i, int j){
    // Ray ray();
    // return ray;
  }




  Vector3D PerspectiveCamera::getNonColinear(Vector3D vec) {
    Vector3D nonColinearVec(vec);

    if(vec[0] <= vec[1] && vec[0] <= vec[2]) {
      nonColinearVec.set(1.0, vec[1], vec[2]);
    } else if(vec[1] <= vec[0] && vec[1] <= vec[2]) {
      nonColinearVec.set(vec[0], 1.0, vec[2]);
    } else if(vec[2] <= vec[1] && vec[2] <= vec[1]) {
      nonColinearVec.set(vec[0], vec[1], 1.0);
    }
    return nonColinearVec;
  }

}
