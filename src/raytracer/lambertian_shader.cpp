#include "lambertian_shader.h"

namespace raytracer {


  LambertianShader::LambertianShader(float red, float green, float blue) {
    diffuseColor.set(red, green, blue);
  }

  Vector3D LambertianShader::getColor() {
    return diffuseColor;
  }

  void LambertianShader::setColor(Vector3D color) {
    //this->diffuseColor.set(color[0], color[1], color[2]);
    diffuseColor = color;
  }

  // Vector3D LambertianShader::getColor(Vector3D intensity, Vector3D light, Vector3D surfaceNormal, Vector3D view) {
  // }


} /** end  raytracer*/
