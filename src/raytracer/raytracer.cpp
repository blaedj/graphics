
#include "raytracer.h"

namespace raytracer {

  Raytracer::Raytracer(Scene *scene, GraphicsArgs arguments){
    //this->args = arguments;
    //this->args = new AArgs();
    this->outFileName = arguments.outputFileName;
    this->height = arguments.height;
    this->width = arguments.width;
    this->scene = scene;
  }

  Raytracer::Raytracer(){}


  void Raytracer::render() {
    // string outFileName = args.outputFileName;
    // int width = args.width;
    // int height = args.height;

    png::image<png::rgb_pixel> imageData(width, height);
    Vector3D color;
    Ray r;
    float tmin, tmax;
    tmin = 1.0;    //TODO: what should min be?
    tmax = FLT_MAX;

    Camera *selectedCamera = scene->cameraList.at(0);
    /**HACK***/
    selectedCamera->imageWidth = width;
    selectedCamera->imageHeight = height;
    /**END HACK***/

    cout << "width :" << width << endl;

    cout << "imageData.get_width() :" << imageData.get_width() << endl;
    for (size_t y = 0.0; y < imageData.get_height(); ++y) {
      for (size_t x = 0.0; x < imageData.get_width(); ++x) {
	assert(y >= 0);
	assert(y <= height);
	assert(x >= 0 && x < width);
	r = selectedCamera->computeRay(x, y, r);

	color = computeRayColor(r, tmin, tmax);

	color.clamp(0.0, 1.0);

	imageData[y][x] = png::rgb_pixel(color[0] * 255, color[1] * 255,
					 color[2] * 255);
      }
    }
    imageData.write(outFileName);
  }

  HitInfo Raytracer::getNearestHit(float tmin, Ray& ray, float& tmax) {

    float smallestDist = FLT_MAX;
    Shape *currShape;
    HitInfo hitStruct;
    HitInfo nearestHit;

    /** TOBE REPLACED BY BVH**/
    for (int i = 0; i < scene->shapeList.size(); i++) {
      currShape = scene->shapeList[i];
      hitStruct = currShape->closestHit(ray, tmin, tmax);

      if (hitStruct.hit && hitStruct.distance <= smallestDist) {
	smallestDist = hitStruct.distance;
	nearestHit = hitStruct;
      }
    }
    return nearestHit;
  }

  bool Raytracer::anyHit(float tmin, Ray& ray, float& tmax){
    Shape *currShape;
    HitInfo hitStruct;

    /** TOBE REPLACED BY BVH**/
    for (int i = 0; i < scene->shapeList.size(); i++) {
      currShape = scene->shapeList[i];
      hitStruct = currShape->closestHit(ray, tmin, tmax);

      if (hitStruct.hit) {
	return true;
      }
    }
    return false;
  }

  // find closest object
  // apply_shader()
  // return color;
  Vector3D Raytracer::computeRayColor(Ray &ray, float tmin, float &tmax) {

    float marginError = .0001f;
    Vector3D tempColor(0.0, 0.0, 0.0);
    Vector3D backgroundColor(0.1,0.1,0.1);
    /*********************************/
    struct HitInfo nearestHit;

    /** TOBE REPLACED BY BVH**/
    nearestHit = getNearestHit(tmin, ray, tmax);

    if(!nearestHit.hit || !nearestHit.hitShape ){
      return backgroundColor;
    }else {
      Light *l;
      Shader *sh = nearestHit.shader;
      Vector3D pointHit = ray.origin + (ray.direction * nearestHit.distance);
      Vector3D viewDir = scene->cameraList[0]->location - pointHit;
      viewDir.normalize();

      for ( int i = 0; i < scene->lightList.size(); i++ ) {
	l = scene->lightList[i];
	Vector3D lightDir = l->position - pointHit;
	lightDir.normalize();
	Ray shadowRay(pointHit, lightDir );

	if(!anyHit(marginError, shadowRay, tmax )) {
	  // make sure nearestHit has reference to the shape it hit.
	  assert(nearestHit.hitShape);
	  Shape *nearShp = nearestHit.hitShape;

	  Vector3D intensity, surfaceNormal;
	  intensity = l->intensity;

	  try {
	    cout << "nearShp->name :" << nearShp->name << endl;
	  } catch(...){
	    cout << "unable to access the name of the nearShp" << endl;
	  }

	  surfaceNormal = nearShp->normalAtPoint(pointHit);

	  tempColor += sh->calculateColor(intensity, lightDir,
					  surfaceNormal, viewDir);
	}
      }
    }
    return tempColor;
  }
}
