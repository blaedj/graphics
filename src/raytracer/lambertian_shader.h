#ifndef _LAMBERTIAN_SHADER_H_
#define _LAMBERTIAN_SHADER_H_

// tmax should be the length of the ray from point to shader
// light direction vecotr should be normalized!!
//  - this should occur in the c += kdllmax(U, n (dot) lightdir)

//optimizations for 'anyhit'

private Shape* lastObjectHit;

//void visiblityQuery(----){
  //check the ray against last known hit object (last object hit)
  // compare the ray against that last hit object first, then start the typical
  // 'anyHit' check.

//}

#endif /* _LAMBERTIAN_SHADER_H_ */
