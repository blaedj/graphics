#include "box.h"


namespace raytracer {

  Box::Box(Vector3D near, Vector3D far, Shader *sh) {
    this->m_sh = sh;
    setShader(sh);
    double x, y, z, w, l, h;
    // xyz coords of near point.
    x = near[0];
    y = near[1];
    z = near[2];
    // width, height, depth of box.
    l = far[0] - near[0];
    h = far[1] - near[1];
    w = far[2] - near[2];

    double wh, lh, hh;
    wh = w/2.0;
    lh = l/2.0;
    hh = h/2.0;


    Vector3D tlf,//top left front
      blf,// bottom left front
      trf,// top right front
      brf,//
      tlb,//
      blb,//
      trb,//
      brb;//bottom right back

    tlf = Vector3D(x-wh, y+hh, z-lh);
    blf = Vector3D(x-wh, y-hh, z-lh);
    trf = Vector3D(x+wh, y+hh, z-lh);
    brf = Vector3D(x+wh, y-hh, z-lh);
    tlb = Vector3D(x-wh, y+hh, z+lh);
    blb = Vector3D(x-wh, y-hh, z+lh);
    trb = Vector3D(x+wh, y+hh, z+lh);
    brb = Vector3D(x+wh, y-hh, z+lh);

    //front face
    addTriangle(tlf, trf, brf);
    addTriangle(tlf, brf, blf);

    //left side
    addTriangle(tlb, blf, blb);
    addTriangle(tlb, tlf, blf);

    //right side
    addTriangle(trb, brb, brf);
    addTriangle(trb, brf, trf);

    //back face
    addTriangle(tlb, brb, trb);
    addTriangle(tlb, blb, brb);

    //top
    addTriangle(tlf, tlb, trb);
    addTriangle(tlf, trb, trf);

    //bottom
    addTriangle(blf, brb, blb);
    addTriangle(blf, brf, brb);
  }

  void Box::setShader(raytracer::Shader *sh){
    if(!sh){
      Vector3D color(.2, .2, .2);
      this->m_sh = new SolidShader(color);
    } else {
      this->m_sh = sh;
    }
  }

  HitInfo Box::closestHit(const Ray &ray, float tmin, float &tmax) {
    float smallestDist = FLT_MAX;
    HitInfo nearestHit;
    nearestHit.hit = false;
    HitInfo hitStruct;
    for(std::vector<Triangle>::iterator iter = m_triangles.begin();
	iter != m_triangles.end(); ++iter){
      hitStruct = iter->closestHit(ray, tmin, tmax);

      if (hitStruct.hit && hitStruct.distance <= smallestDist) {
	smallestDist = hitStruct.distance;
	// set nearestHit's info equal to hitStructs
	nearestHit.hit = hitStruct.hit;
	nearestHit.distance = hitStruct.distance;
	nearestHit.surfaceNormal = hitStruct.surfaceNormal;
	nearestHit.shader = hitStruct.shader;
	nearestHit.hitShape = hitStruct.hitShape;
	nearestHit = hitStruct;
      }
    }
    return nearestHit;
  }


  Vector3D Box::applyShader(){
    return this->m_sh->getColor();
  }

  /* This may suffice because the normalAtPoint will be called on the triangle
   *   that is contained in the box, not the box itself.
   */
  Vector3D Box::normalAtPoint(Vector3D point) {
    return Vector3D();
  }

  void Box::addTriangle(Vector3D a, Vector3D b, Vector3D c) {
    Triangle tr(a, b, c, m_sh);
    this->m_triangles.push_back(tr);
  }

}
