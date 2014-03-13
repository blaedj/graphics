

#include "triangle.h"


using namespace std;
using namespace sivelab;

namespace raytracer {

  Triangle::Triangle(Vector3D vert1, Vector3D vert2, Vector3D vert3, Shader *shadr) {
    this->p1 = vert1;
    this->p2 = vert2;
    this->p3 = vert3;
    this->shader = shadr;
    this->normal = (p2 - p1).cross(p3 - p1);
    normal.normalize();
  }

  HitInfo Triangle::closestHit(const Ray &ray, float tmin, float &tmax) {
    struct HitInfo hitStruct;

    Vector3D rayDir = ray.direction;
    Vector3D rayOrig = ray.origin;
    float a, b, c, d, e, f, g, h, i, j, k, l, M;
    float beta, gamma, t;

    a = p1[0] - p2[0];
    b = p1[1] - p2[1];
    c = p1[2] - p2[2];

    d = p1[0] - p3[0];
    e = p1[1] - p3[1];
    f = p1[2] - p3[2];

    g = rayDir[0];
    h = rayDir[1];
    i = rayDir[2];
    /* e = ray origin
       |j|   |xa - xe|
       |k| = |ya - ye|
       |l|   |za - ze| */
    j = p1[0] - rayOrig[0];
    k = p1[1] - rayOrig[1];
    l = p1[2] - rayOrig[2];
    /* M = a(ei - hf) + b(gf - di) + c(dh - eg) */
    M = a*(e*i - h*f) + b*(g*f - d*i) + c*(d*h - e*g);

    t = -( f*(a*k - j*b) + e*(j*c - a*l) + d*(b*l - k*c)) / M;
    if(t < tmin || t > tmax) {
      hitStruct.hit = false;
      return hitStruct;
    }

    gamma = (i*(a*k-j*b) + h*(j*c - a*l) + g*(b*l - c*k)) / M;
    if(gamma < 0 || gamma > 1) {
      hitStruct.hit = false;
      return hitStruct;
    }

    beta = (j*(e*i - h*f) + k*(g*f - d*i) + l*(d*h - e*g)) / M;
    if(beta < 0 || beta > 1 - gamma) {
      hitStruct.hit = false;
      return hitStruct;
    }
    hitStruct.distance = t;
    hitStruct.hitShape = this;
    hitStruct.hit = true;
    hitStruct.shader = this->shader;
    hitStruct.surfaceNormal = this->normal;

    return hitStruct;

  }

  Vector3D Triangle::applyShader() {
    return this->shader->getColor();
  }

  Vector3D Triangle::normalAtPoint(Vector3D point) {
    return this->normal;
  }


} /** end  raytracer*/
