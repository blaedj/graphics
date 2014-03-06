#ifndef _SHADER_H_
#define _SHADER_H_

class Shader
{
public:
  Shader() {}
  virtual ~Shader() { }

  virtual Vector3D getColor() = 0;

};

#endif /* _SHADER_H_ */
