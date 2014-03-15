#ifndef _BLINN_PHONG_H_
#define _BLINN_PHONG_H_

#include "shader.h"
#include "Vector3D.h"

namespace raytracer {

  class BlinnPhong : public Shader {

  public:
    BlinnPhong(Vector3D surfaceColor, Vector3D specColor,
	       float phongExponent, float mirror);
    Vector3D calculateColor(Vector3D intensity, Vector3D lightDir, Vector3D normal, Vector3D viewDir);
    Vector3D getColor();
    virtual void setColor(Vector3D color);


  private:
    Vector3D surfaceColor;
    Vector3D specularColor;
    float phongExp;
    float mirror;

  };


} /** end  raytracer*/

#endif /* _BLINN_PHONG_H_ */
