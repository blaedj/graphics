#include "sphere.h"

using namespace std;

namespace raytracer {

  Sphere::Sphere(Vector3D center, double radius){
    this->center = center;
    this->radius = radius;
  }

  // if yes, then the ray intersects the sphere surface at magnitude 't'.
  bool Sphere::closestHit( const Ray &ray, float &dist){
    // the question to answer is: Does plugging t into the equation return 0?
    // if yes, then the ray intersects the sphere surface at magnitude 't'.
    // t: a(t * t) + B*t + c = 0?
    float a = ray.direction.dot(ray.direction);
    float b = 2 * ray.direction.dot(ray.origin);
    float c = ray.origin.dot(ray.origin) - (this->radius * this->radius);
    float discriminant = b * b - 4 * a * c;
    if ( discriminant > 0.0 ) {
      return false;
    }

    float distanceRoot = sqrtf(discriminant);
    float t; // intersection 't'
    if(b < 0.0) {
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
    if(t1 < 0){ return false;}

    if(t0 < 0) { //intersection point must be positive, so return t1.
      dist = t1;
      return true;
    } else { // t0 is the intersection point.
      dist = t0;
      return true;
    }
  }


} /** end raytracer */
