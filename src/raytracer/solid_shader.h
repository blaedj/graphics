#ifndef _SOLID_SHADER_H_
#define _SOLID_SHADER_H_

#include "Vector3D.h"

namespace raytracer {

  class SolidShader : public Shader
  {
  public:
    SolidShader() { }

    SolidShader(Vector3D colors) {
      this->color = colors;
    };

    virtual ~SolidShader() { }


    Vector3D getColor() {
      return color;
    }

    virtual Vector3D calculateColor(Vector3D intensity, Vector3D light, Vector3D normal, Vector3D view) {
      return color;
    };

    virtual void setColor(Vector3D color) {
      this->color.set(color[0], color[1], color[2]);
    };

  private:
    Vector3D color;
    void setShader(Shader *sh);

  };


} /** end  raytracer*/

#endif /* _SOLID_SHADER_H_ */
