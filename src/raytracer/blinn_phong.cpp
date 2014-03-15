#include "blinn_phong.h"

namespace raytracer {

  BlinnPhong::BlinnPhong(Vector3D surfaceColor, Vector3D specColor, float phongExponent, float mirror){
    this->surfaceColor = surfaceColor;
    this->specularColor = specColor;
    this->phongExp = phongExponent;
    this->mirror = mirror;
  }

  Vector3D BlinnPhong::calculateColor(Vector3D intensity, Vector3D lightDir,
				      Vector3D normal, Vector3D viewDir){
    normal.normalize();
    viewDir.normalize();
    lightDir.normalize();

    Vector3D h = viewDir + lightDir;
    h.normalize();

    float normLightMax = max(0.0, normal.dot(lightDir));
    float maxNormH = max(0.0, normal.dot(h));


    float redLight, greenLight, blueLight;
    float red, green, blue;
    redLight = intensity[0];
    greenLight = intensity[1];
    blueLight = intensity[2];

    //diffuse
    red = surfaceColor[0] * redLight * normLightMax;
    green = surfaceColor[1] * greenLight * normLightMax;
    blue = surfaceColor[2] * blueLight * normLightMax;

    //specular
    red += specularColor[0] * redLight * pow(maxNormH, phongExp);
    green += specularColor[1] * greenLight * pow(maxNormH, phongExp);
    blue += specularColor[2] * blueLight * pow(maxNormH, phongExp);

    Vector3D color(red, green, blue);
    return color;
  }

  Vector3D BlinnPhong::getColor(){
    return surfaceColor;
  }

   void BlinnPhong::setColor(Vector3D color){
     surfaceColor = color;
  }
} /** end  raytracer*/
