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

  Vector3D LambertianShader::calculateColor(Vector3D intensity, Vector3D lightDir,
					    Vector3D normal, Vector3D view) {
    //color: diffuse * intensity * max(0, normal dot lightDir) for each red, green and blue
    float red = diffuseColor[0] * intensity[0] * max(0.0, normal.dot(lightDir));
    float green = diffuseColor[1] * intensity[1] * max(0.0, normal.dot(lightDir));
    float blue = diffuseColor[2] * intensity[2] * max(0.0, normal.dot(lightDir));
    return Vector3D(red, green, blue);
    //return diffuseColor;
  }


} /** end  raytracer*/
