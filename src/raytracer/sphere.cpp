#include "sphere.h"
#include "solid_shader.h"

using namespace std;

namespace raytracer {

  Sphere::Sphere(Vector3D center, double radius){
    this->center = center;
    this->radius = radius;
    Vector3D color(0.9, 1.0, 0.0);
    Shader *solidColor = new SolidShader(color);
    this->shader = solidColor;
  }

  Sphere::Sphere(Vector3D center, double radius, Shader *shader){
    this->center = center;
    this->radius = radius;
    this->shader = shader;
  }

  Vector3D Sphere::applyShader(){
    return this->shader->getColor();
  }

  HitInfo Sphere::closestHit( const Ray &ray){
    // the question to answer is: Does plugging t into the equation return 0?
    // if yes, then the ray intersects the sphere surface at magnitude 't'.
    // t: a(t * t) + B*t + c = 0?
    float eps = .001;
    struct HitInfo hitStruct;
    hitStruct.hit = false;

    float a = pow(ray.direction.dot(ray.origin - this->center), 2.0);
    float b = (ray.origin - this->center).dot(ray.origin - this->center);
    //float b = 2 * ray.direction.dot(ray.origin);
    float c = (b - (this->radius * this->radius));

    float discriminant = a - ((ray.direction.dot(direction)) * c);//b * b - 4 * a * c;

    if ( discriminant >= eps ) {
      hitStruct.hit = false;
      return hitStruct;
    } else {
      float distanceRoot = sqrtf(discriminant);
      float t; // intersection 't'
      if(b < eps) {
	t = (-b - distanceRoot) / 2.0;
      } else {
	t = (-b + distanceRoot) / 2.0;
      }

      // the two intersection points:
      float t0 = t / a;
      float t1 =  c / t;

      //make t0 the largest of the 2 possible intersection points along the ray.
      t0 = (t0 < t1) ? t1 : t0;

      // if t1 < zero, the sphere is behind the ray origin, no intersection.
      if(t1 < eps) {
	hitStruct.hit = false;
      }if(t0 < eps) { //intersection point must be positive, so return t1.
	hitStruct.distance = t1;
	hitStruct.hit = true;
      } else { // t0 is the intersection point.
	hitStruct.distance = t0;
	hitStruct.hit = true;
      }
    }
    return hitStruct;
  }


} /** end raytracer */
