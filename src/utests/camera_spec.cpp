#include <cstdlib>
#include "camera.h"

using namespace raytracer;
using namespace sivelab;
using namespace std;

int main(int argc, char *argv[])
{

  Vector3D location(1.0,2.0,1.0);
  raytracer::Camera cam(location);
  cout << "the coords, x, y and z are:\n";
  cout << cam.aX << endl << cam.aY << endl << cam.aZ << endl;

}
