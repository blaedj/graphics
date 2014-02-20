#include "perspective_camera.h"

using namespace std;

namespace raytracer {

PerspectiveCamera::~PerspectiveCamera(){}

PerspectiveCamera::PerspectiveCamera() {}

PerspectiveCamera::PerspectiveCamera(sivelab::Vector3D location) :
						Camera(location) { }

PerspectiveCamera::PerspectiveCamera(Vector3D location, Vector3D direction) :
										  Camera(location, direction) {
}

Ray PerspectiveCamera::computeRay(int i, int j){


	float leftBound = -(imageWidth/2);
	float rightBound = (imageWidth/2);
	float bottomBound = -(imageHeight/2);
	float topBound = (imageHeight/2);

	double rayU = leftBound + (rightBound - leftBound)*(i + 0.5) / imageWidth;
	double rayV = bottomBound + (topBound - bottomBound)*(j + 0.5) / imageHeight;

	//	 ray.direction = -d*W + u*U + v*V
	// ray.origin = e;// e => camera origin
	const Vector3D rayDirection = ((-1.0 ) * this->focalLength)*(this->orthoBasis.W) + (rayU * this->orthoBasis.W) + (rayV * this->orthoBasis.V);

	const Vector3D rayOrigin = this->location;
	Ray ray(rayOrigin, rayDirection);
}

}
