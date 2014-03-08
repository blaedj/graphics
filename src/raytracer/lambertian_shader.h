#ifndef _LAMBERTIAN_SHADER_H_
#define _LAMBERTIAN_SHADER_H_

// tmax should be the length of the ray from point to shader
// light direction vecotr should be normalized!!
//  - this should occur in the c += kdllmax(U, n (dot) lightdir)

//optimizations for 'anyhit'

//private Shape* lastObjectHit;

//void visiblityQuery(----){
//check the ray against last known hit object (last object hit)
// compare the ray against that last hit object first, then start the typical
// 'anyHit' check.

//}
#include "Vector3D.h"
#include "shader.h"

using namespace std;
using namespace sivelab;

namespace raytracer {

  class LambertianShader : public Shader
  {
  public:
    LambertianShader() {}
    LambertianShader(float red, float green, float blue);

    virtual ~LambertianShader() {}
    Vector3D getColor();
    virtual void setColor(Vector3D color);

    Vector3D getColor(Vector3D intensity, Vector3D light, Vector3D surfaceNormal, Vector3D view);

    virtual Vector3D calculateColor() {
      Vector3D vec;
      return vec;
    };

  private:
    Vector3D diffuseColor;

  };


} /** end  raytracer*/

#endif /* _LAMBERTIAN_SHADER_H_ */
