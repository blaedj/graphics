
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
#include "raytracer.h"
#include "rasterizer.h"
#include "matrix4x4.h"

using namespace sivelab;
using namespace std;
using namespace raytracer;
using namespace rasterizer;

bool useRaytracing(GraphicsArgs args);
void matrixTests();
void testVectMult();
void test3x3Determ();
void test4x4Determ();
void testCofactor();

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
  return 0;
}

int main(int argc, char *argv[])
{
  GraphicsArgs args;
  args.process(argc, argv);
  string filename = args.inputFileName;

#if 1
  //runTests(args);
  clock_t init, final;
  init=clock();


  XMLSceneParser xmlParser;

  Scene *scene = new Scene();
  xmlParser.registerCallback("camera", scene);
  xmlParser.registerCallback("light", scene);
  xmlParser.registerCallback("shader", scene);
  xmlParser.registerCallback("shape", scene);
  xmlParser.parseFile(filename);
  assert(scene->lightList.size() > 0);
  assert(scene->shapeList.size() > 0);
  assert(scene->cameraList.size() > 0);

  if(useRaytracing(args)){
    Raytracer rt(scene, args);
    rt.render();
    ///    scene->render(args.outputFileName, args.width, args.height);
  } else { // use rasterizer
    Rasterizer raster(scene, args);
    raster.render();
  }

  final=clock()-init;
  cout << "render time was: " << (double)final / ((double)CLOCKS_PER_SEC) << " seconds.\n";
#endif
  //TESTING/////
  /*  matrixTests();
  testVectMult();
  test3x3Determ();
  test4x4Determ();*/
  //testCofactor();
  //testTranspose();

  return 0;
}

void matrixTests() {
  Matrix4x4 matr(1.0, 2.0, 2.0, 4.0,
		 2.0, 1.0, 1.0, 1.0,
		 1.0, 1.0, 1.0 ,1.0,
		 1.0, 1.0, 1.0, 1.0);
  matr.print();
  Matrix4x4 matr2(1.0, 2.0, 2.0, 4.0,
  		  5.0, 5.0, 4.0, 3.0,
  		  2.0, 2.0, 6.0, 5.0,
  		  5.0, 5.0, 4.0, 3.0);

  Matrix4x4 result;
  result = matr * matr2;
  cout << "multiplying two matrices:\n";
  result.print();

  matr.setIdentity();
  cout << "Setting identity matrix\n";
  matr.print();
}

void testVectMult(){
  Matrix4x4 matr;
  Vector3D result = matr.multVector(Vector3D(1,1,1), 5.0);
  cout << "[1 1 1] vector times 5:"
       << "\n" << result << "\n";
}

void test3x3Determ() {
  Matrix3x3 matr(1,2,3,
		 3,2,1,
		 2,1,3);
  double det = matr.determinant();
  cout << "Deteminant of 3x3 is: " << det << endl;
  cout << "Should be -12\n";
}

void test4x4Determ() {
  Matrix4x4 matr(3, 0, 2, -1,
		 1, 2, 0, -2,
		 4, 0, 6, -3,
		 5, 0, 2, 0);

    cout << "Deteminant should be 20\n"
	 << "Actual: " << matr.determinant() << endl;
}

void testCofactor(){
  Matrix4x4 matr(1.0, 2.0, 2.0, 4.0,
		 2.0, 3.0, 2.0, 1.0,
		 1.0, 1.0, 2.0 ,1.0,
		 1.0, 5.0, 1.0, 1.0);

  cout << "Cofactor should be: 2\n"
       << "actual: " << matr.cofactor(1,1) << endl;
}

bool useRaytracing(GraphicsArgs args){
  return true;
}
