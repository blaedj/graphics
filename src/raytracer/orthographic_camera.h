/*
 * OrthographicCamera.h
 *
 *  Created on: Feb 15, 2014
 *      Author: Blaed
 */

#ifndef __RAYTRACER_ORTHOGRAPHICCAMERA_H_
#define __RAYTRACER_ORTHOGRAPHICCAMERA_H_

#include "camera.h"
#include "ray.h"

namespace raytracer {

class OrthographicCamera: public raytracer::Camera {
public:
	OrthographicCamera();
	virtual ~OrthographicCamera();

	//! Constructor from only the location.
	OrthographicCamera(Vector3D location);

	//! Constructor from camera location and direction.
	OrthographicCamera(Vector3D location, Vector3D direction);

	void setHeightWidth(float height, float width){imageWidth = width; imageHeight = height;}

	Ray computeRay(int i, int j);

private:
	float imageWidth;
	float imageHeight;
};

}

#endif /* __RAYTRACER_ORTHOGRAPHICCAMERA_H_ */
