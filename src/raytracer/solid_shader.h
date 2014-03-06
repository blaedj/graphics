#ifndef _SOLID_SHADER_H_
#define _SOLID_SHADER_H_

#include "Vector3D.h"

class SolidShader : public Shader
{
public:
  SolidShader() : Shader() { }

  SolidShader(Vector3D colors) {
    this->color = colors;
  };

  virtual ~SolidShader() { }


  Vector3D getColor() {
    return color;
  }

private:
  Vector3D color;


};

#endif /* _SOLID_SHADER_H_ */
