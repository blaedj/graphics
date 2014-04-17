#include "sphere.h"
#include "solid_shader.h"

using namespace std;

namespace raytracer {
  bool inBounds(HitInfo hitStruct, float tmin, float &tmax );

  Sphere::Sphere(Vector3D center, double radius) {
    this->center = center;
    this->radius = radius;
    //Vector3D color(drand48(), drand48(), drand48());
    Vector3D color(0.0, 0.0, 1.0);
    Shader *solidColor = new SolidShader(color);
    this->shader = solidColor;
  }

  Sphere::Sphere(Vector3D center, double radius, Shader *shader) {
    this->center = center;
    this->radius = radius;
    this->shader = shader;
    assert(shader);
  }

  Vector3D Sphere::applyShader() {
    return this->shader->getColor();
  }

  HitInfo Sphere::closestHit( const Ray &ray, float tmin, float &tmax) {
    // the question to answer is: Does plugging t into the equation return 0?
    // if yes, then the ray intersects the sphere surface at magnitude 't'.
    // t: a(t * t) + B*t + c = 0?
    struct HitInfo hitStruct;
    hitStruct.hit = true;
    float a, b, c, distance;

    Vector3D o = ray.origin;
    Vector3D d = ray.direction;
    Vector3D center = this->center;
    float r = this->radius;

    a = d.dot(d);
    b = d.dot(o);
    c = o.dot(o) - (r * r);

    float t0, t1;
    float discriminant = (b * b) - 4 * a * c;
    if(discriminant < 0) { // no real solutions, so no intersection.
      hitStruct.hit = false;// no hit!
      return hitStruct;
    } else { //there are real solutions
      float discSqrt = sqrtf(discriminant);
      float q;
      if(b < 0)
	q = (-b - discSqrt)/ 2.0;
      else
	q = (-b + discSqrt)/ 2.0;

      t0 = q / a;
      t1 = c / q;

      if(t0 > t1){ // set t1 to be the greatest solution.
	float temp = t0;
	t0 = t1;
	t1 = temp;
      }
      if(t1 > 0){
	if(t0 < 0.0) distance = t1; // t0 is not a valid solution, so distance is t1
	else distance = t0; // t0 is the minimal solution and is > 0, so it is the distance of the closest hit.
      } else { // the greatest solution is < 0, so no intersection
	hitStruct.hit = false;
	return hitStruct;
      }
      // fill in point of intersection information
      hitStruct.hit = true;
      hitStruct.distance = distance;
      hitStruct.hitShape = this;
      hitStruct.shader = this->shader;
      return hitStruct;
    }
  }

  bool inBounds(HitInfo hitStruct, float tmin, float &tmax )
  {
    return hitStruct.distance > tmin && hitStruct.distance < tmax;
  }

  Vector3D Sphere::normalAtPoint(Vector3D point) {
    Vector3D normalAt;
    normalAt = point - this->center;
    normalAt.normalize();
    return normalAt;
  }

} /** end raytracer */
