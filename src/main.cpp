
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "png++/png.hpp"
#include "handleGraphicsArgs.h"
#include "Random.h"
#include "Vector3D.h"
#include "camera.h"
#include "orthographic_camera.h"
#include "perspective_camera.h"
#include "camera_creator.h"
#include "XMLSceneParser.h"
#include "handleGraphicsArgs.h"
#include "scene.h"
#include "shape.h"
#include "basis.h"

using namespace sivelab;
using namespace std;
using namespace raytracer;



void testXMLparsing(string fileName) {
  XMLSceneParser xmlParser;
  //CameraCreator *camBuilder = new CameraCreator();
  Scene *scene = new Scene();

  xmlParser.registerCallback("camera", scene);
  xmlParser.registerCallback("light", scene);
  xmlParser.registerCallback("shader", scene);
  xmlParser.registerCallback("shape", scene);
  //  xmlParser.registerCallback("instance", scene);
  xmlParser.parseFile(fileName);
}

int runTests(GraphicsArgs args)
{
  float w = args.width;
  float h = args.height;
  png::image< png::rgb_pixel > imData( w, h );
  testXMLparsing(args.inputFileName);
}

int main(int argc, char *argv[])
{
  GraphicsArgs args;
  args.process(argc, argv);
  string filename = args.inputFileName;

  //runTests(args);
  clock_t init, final;
  init=clock();


  XMLSceneParser xmlParser;

  Scene *scene = new Scene();
  xmlParser.registerCallback("camera", scene);
  xmlParser.registerCallback("light", scene);
  xmlParser.registerCallback("shader", scene);
  xmlParser.registerCallback("shape", scene);
  //  xmlParser.registerCallback("instance", scene);
  xmlParser.parseFile(filename);
  assert(scene->lightList.size() > 0);
  assert(scene->shapeList.size() > 0);
  assert(scene->cameraList.size() > 0);

  scene->render(args.outputFileName, args.width, args.height);

  final=clock()-init;
  cout << "render time was: " << (double)final / ((double)CLOCKS_PER_SEC) << " seconds.\n";

  return 0;
}
