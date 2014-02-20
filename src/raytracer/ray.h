#ifndef __RAYTRACER_RAY_H_
#define __RAYTRACER_RAY_H_

#include "Vector3D.h"
using namespace sivelab;

class Ray
{
public:
	Vector3D origin;
	Vector3D direction;

	//! Default constructor
	Ray(void);

	Ray(const Vector3D& origin, const Vector3D& direction) {
		this->origin = origin;this->direction = direction;
	}

	virtual ~Ray() {};

};

#endif /* __RAYTRACER_RAY_H_ */
