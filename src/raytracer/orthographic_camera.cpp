/*
 * OrthographicCamera.cpp
 *
 *  Created on: Feb 15, 2014
 *      Author: blaed
 */

#include "orthographic_camera.h"

namespace raytracer {

  OrthographicCamera::OrthographicCamera() : Camera() {
    viewDirection.set(0.0,0.0,0.1);
  }

  OrthographicCamera::~OrthographicCamera() {}

  OrthographicCamera::OrthographicCamera(Vector3D location,std::string name, float focalLength, float imagePlaneWidth) : Camera(location, name, focalLength, imagePlaneWidth){ }

  OrthographicCamera::OrthographicCamera(Vector3D location, Vector3D direction, std::string name, float focalLength, float imagePlaneWidth) :
    Camera(location, direction, name, focalLength, imagePlaneWidth){ }

  Ray OrthographicCamera::computeRay(int i, int j, Ray &r){
    /**Need to fit image of nx x ny pixels into rectangle of size
     * l = left, r = right, b = bottom, t = top boundary if image plane
     * (r − l)x(t − b)
     * u = l + (r − l)(i + 0.5)/nx
     * v = b + (t − b)(j + 0.5)/ny */

    float leftBound = -(imageWidth/2);
    float rightBound = (imageWidth/2);
    float bottomBound = -(imageHeight/2);
    float topBound = (imageHeight/2);

    double rayU = leftBound + (rightBound - leftBound)*(i + 0.5) / imageWidth;
    double rayV = bottomBound + (topBound - bottomBound)*(j + 0.5) / imageHeight;
    //	Ray r;
    //	r.direction = −W ;
    //	r.origin = e + u U + v V ;

    const Vector3D rayDirection = this->viewDirection;
    const Vector3D rayOrigin = this->location + (rayU*orthoBasis.U) + rayV*orthoBasis.V ;
    r.origin = rayOrigin;
    r.direction = rayDirection;
    return r;
  }
}
