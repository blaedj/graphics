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
    hitStruct.hit = false;
    float u, f, t0, t1; // intersection distance 't'
    float a = pow(ray.direction.dot(ray.origin - this->center), 2.0);

    float b = (ray.origin - this->center).dot(ray.origin - this->center);

    float c = (b - (this->radius * this->radius));


    float discriminant = a - ((ray.direction.dot(ray.direction)) * (c));
    //discriminant = //b^2 - 4 * a * c;
	if ( discriminant < 0 ) {
	  hitStruct.hit = false;
	  return hitStruct;
	} else {
	  u = ray.direction.dot(ray.direction);
	  f = (-1.0) * ray.direction.dot(ray.origin - this->center);
	  float distanceRoot = sqrtf(discriminant);


	  t0 = (f + distanceRoot) / u;
	  t1 = (f - distanceRoot) / u;
	  hitStruct.distance = (t0 > t1) ? t1 : t0;
	  if(!inBounds(hitStruct, tmin, tmax)) {
	    hitStruct.hit = false;
	    return hitStruct;
	  }

	  hitStruct.shader = this->shader;
	  hitStruct.hitShape = this;
	  hitStruct.hit = true;
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
