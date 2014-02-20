
#include <iostream>
#include <cstdlib>

#include "png++/png.hpp"
#include "handleGraphicsArgs.h"
#include "Random.h"
#include "Vector3D.h"
#include "camera.h"
#include "orthographic_camera.h"
#include "perspective_camera.h"

using namespace sivelab;
using namespace std;
using namespace raytracer;


void testOrthographicRayCompute(int h, int w, png::image<png::rgb_pixel> imData)
{
  OrthographicCamera *cam = new OrthographicCamera();
  cam->setHeightWidth(h, w);
  for (unsigned int idx=0; idx<imData.get_height()*imData.get_width(); ++idx)
    {
      size_t x = idx % w;
      size_t y = static_cast<size_t>( floor(idx / static_cast<float>(imData.get_width())) );
      //		cout << x << endl;
      //		cout << y << endl;
      assert((y >= 0) && (y < h) && x >= 0 && x < w);
      Ray r = cam->computeRay(x, y);

      Vector3D k = r.origin;
      k.normalize();
      k.set((k[0] + 1.0) / 2.0,(k[1] + 1.0) / 2.0, (k[2] + 1.0) / 2.0);

      //		Vector3D c()
      //Vector3D c(static_cast<int>(floor(k[0])),
      //	 static_cast<int>(floor(k[1])),
      //static_cast<int>(floor(k[2])));

      // The origin for indexing the height is in lower left...


      imData[y][x] = png::rgb_pixel( k[0] * 255.0,
				     9.0,
				     //				     k[1] * 255.0,
				     k[2] * 255.0);
    }
  imData.write("ortho.png");
}

void testPerspectiveCamera(int h, int w, png::image<png::rgb_pixel> imData)
{
  PerspectiveCamera *cam = new PerspectiveCamera();
  cam->setHeightWidth(h, w);
  for (unsigned int idx=0; idx<imData.get_height()*imData.get_width(); ++idx)
    {
      size_t x = idx % w;
      size_t y = static_cast<size_t>( floor(idx / static_cast<float>(imData.get_width())) );
      //		cout << x << endl;
      //		cout << y << endl;
      assert((y >= 0) && (y < h) && x >= 0 && x < w);
      Ray r = cam->computeRay(x, y);

      Vector3D k = r.direction;
      k.normalize();
      k.set(k[0] * 0.5 + .5, k[1] * .5 + .5, k[2] * 0.5 + .5);

      cout << k[0] << endl;
      cout << k[1] << endl;
      cout << k[2] << endl;

      imData[y][x] = png::rgb_pixel( k[0] * 255.0,
				     k[1] * 255.0,
				     k[2] * 255.0);
    }
  imData.write("perspectiveraygeneration.png");
}



int main(int argc, char *argv[])
{
  GraphicsArgs args;
  args.process(argc, argv);
  int w = args.width, h = args.height;
  png::image< png::rgb_pixel > imData( w, h );
  cout << w << endl;
  cout << h << endl;
  testOrthographicRayCompute(h, w, imData);
  testPerspectiveCamera(h, w, imData);
  exit(EXIT_SUCCESS);
}
