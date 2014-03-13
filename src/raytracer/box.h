#ifndef _BOX_H_
#define _BOX_H_


namespace raytracer {

  class Box : public Shape {

    virtual HitInfo closestHit(const Ray &ray, float tmin, float &tmax);
    virtual Vector3D applyShader();
    virtual Vector3D normalAtPoint(Vector3D point);


  }


} /** end  raytracer*/

#endif /* _BOX_H_ */
