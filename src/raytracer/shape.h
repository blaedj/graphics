#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <cstdlib>
namespace raytracer {
  class Shape
  {
  public:
    Shape();
    virtual ~Shape();
    virtual bool closestHit(const Ray &ray);

  };
}

#endif /* _SHAPE_H_ */
