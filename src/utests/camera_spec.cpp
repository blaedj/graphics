#define BOOST_TEST_MODULE CameraTest
#include <boost/test/included/unit_test.hpp>

#include <cstdlib>
#include "camera.h"
#include "Vector3D.h"
#include "basis.h"
#include "perspective_camera.h"

// Name of the test as it is reported when running the tests.
BOOST_AUTO_TEST_SUITE(Camera)

using namespace raytracer;
using namespace sivelab;
using namespace std;

bool vectorsEqual(Vector3D &a, Vector3D &b);
bool checkOrthonormal(Basis basis);


int main(int argc, char *argv[])
{
  Vector3D viewDirection;
  float focalLength;
  float imagePlaneWidth;

  Vector3D location(1.0,2.0,1.0);
  PerspectiveCamera cam(location, "testCamera", .8, .8);
  assert(vectorsEqual(cam.location, location));
  exit(EXIT_SUCCESS);
}

BOOST_AUTO_TEST_CASE(locationSet)
{
  Vector3D viewDirection;
  float focalLength;
  float imagePlaneWidth;

  Vector3D location(1.0,2.0,1.0);
  PerspectiveCamera cam(location, "testCamera", .8, .8);
  BOOST_CHECK(vectorsEqual(cam.location, location));
}

BOOST_AUTO_TEST_CASE (orthonormal)
{
  Vector3D location(1.0,2.0,1.0);
  PerspectiveCamera cam(location, "testCamera", .8, .8);
  // assert(false);//NEED TO IMPLEMENT 2-ARG CAMERA CONSTRUCTOR!!! perspective_camera.cpp
  BOOST_CHECK(checkOrthonormal(cam.orthoBasis));
}

bool checkOrthonormal(Basis basis) {
  Vector3D u = basis.U;
  Vector3D v = basis.V;
  Vector3D w = basis.W;
  BOOST_CHECK(u.dot(v) == 0);
  BOOST_CHECK(u.dot(w) == 0);
  BOOST_CHECK(v.dot(w) == 0);
  return true;
}


bool vectorsEqual(Vector3D &a, Vector3D &b) {
  // cout << "a.x : "<< a[0] << " , b.x :" << b[0] << endl;
  // cout << "a.y : "<< a[1] << " , b.y :" << b[1] << endl;
  // cout << "a.z : "<< a[2] << " , b.z :" << b[2] << endl;

  return a[0] == b[0]
    && a[1] == b[1]
    && a[2] == b[2];
}

BOOST_AUTO_TEST_SUITE_END ()
