#ifndef _SHADER_H_
#define _SHADER_H_

#include "Vector3D.h"

using namespace std;
using namespace sivelab;

namespace raytracer {
  class Shader
  {
  public:
    Shader() {}
    virtual ~Shader() { }

    virtual Vector3D calculateColor(Vector3D intensity, Vector3D lightDir, Vector3D normal, Vector3D viewDir) = 0;

    virtual Vector3D getColor() = 0;
    virtual void setColor(Vector3D color) = 0;

    string name;

  };
} /** end  raytracer*/

#endif /* _SHADER_H_ */
