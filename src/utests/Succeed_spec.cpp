#include <cstdlib>
#include "camera.h"

using namespace raytracer;

int main(int argc, char *argv[])
{

  raytracer::Camera cam;
  if (cam.CameraIsValid()) {
    exit(EXIT_SUCCESS);
  } else {
    exit(EXIT_FAILURE);
  }


}
