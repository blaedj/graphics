#include "Matrix4x4.h"

namespace rasterizer {

  Matrix4x4::Matrix4x4(const double a11, const double a12, const double a13,
		       const double a14, const double a21, const double a22,
		       const double a23, const double a24,const double a31,
		       const double a32, const double a33, const double a34,
		       const double a41, const double a42, const double a43,
		       const double a44)
  {
    set(a11, a12, a13, a14, a21, a22, a23, a24,
	a31, a32, a33, a34, a41, a42, a43, a44);

  }

  Matrix4x4::Matrix4x4() {
    set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  }


  void Matrix4x4::set(const double a11, const double a12, const double a13,
		      const double a14, const double a21, const double a22,
		      const double a23, const double a24,const double a31,
		      const double a32, const double a33, const double a34,
		      const double a41, const double a42, const double a43,
		      const double a44) {
    d[0][0] = a11;
    d[0][1] = a12;
    d[0][2] = a13;
    d[0][3] = a14;

    d[1][0] = a21;
    d[1][1] = a22;
    d[1][2] = a23;
    d[1][3] = a24;

    d[2][0] = a31;
    d[2][1] = a32;
    d[2][2] = a33;
    d[2][3] = a34;

    d[3][0] = a41;
    d[3][1] = a42;
    d[3][2] = a43;
    d[3][3] = a44;

  }

  void Matrix4x4::print() {
    for(int i = 0; i < 4; i++) {
      cout << "| ";
      for(int j = 0; j < 4; j++) {
	cout << d[i][j] << " ";
      }
      cout << "|\n";
    }
  }

  void Matrix4x4::setIdentity() {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
	if(i == j) d[i][j] = 1.0f;
	else d[i][j] = 0.0f;
      }
    }
  }

  const Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &multiplier) const {
    double vals[4][4];
    // TODO: FIX!!
    vals[0][0]= d[0][0] * multiplier.d[0][0] + d[0][1] * multiplier.d[1][0] + d[0][2] * multiplier.d[2][0] + d[0][3] * multiplier.d[3][0];

    vals[0][1]= d[0][0] * multiplier.d[0][1] +
      d[0][1] * multiplier.d[1][1] + d[0][2] * multiplier.d[2][1] + d[0][3] * multiplier.d[3][1];
    vals[0][2]= d[0][0] * multiplier.d[0][2] +
      d[0][1] * multiplier.d[1][2] + d[0][2] * multiplier.d[2][2] + d[0][3] * multiplier.d[3][2];
    vals[0][3]= d[0][0] * multiplier.d[0][3] +
      d[0][1] * multiplier.d[1][3] + d[0][2] * multiplier.d[2][3] + d[0][3] * multiplier.d[3][3];
    vals[1][0]= d[1][0] * multiplier.d[0][0] +
      d[1][1] * multiplier.d[1][0] + d[1][2] * multiplier.d[2][0] + d[1][3] * multiplier.d[3][0];
    vals[1][1]= d[1][0] * multiplier.d[0][1] +
      d[1][1] * multiplier.d[1][1] + d[1][2] * multiplier.d[2][1] + d[1][3] * multiplier.d[3][1];
    vals[1][2]= d[1][0] * multiplier.d[0][2] +
      d[1][1] * multiplier.d[1][2] + d[1][2] * multiplier.d[2][2] + d[1][3] * multiplier.d[3][2];
    vals[1][3]= d[1][0] * multiplier.d[0][3] +
      d[1][1] * multiplier.d[1][3] + d[1][2] * multiplier.d[2][3] + d[1][3] * multiplier.d[3][3];
    vals[2][0]= d[2][0] * multiplier.d[0][0] +
      d[2][1] * multiplier.d[1][0] + d[2][2] * multiplier.d[2][0] + d[2][3] * multiplier.d[3][0];
    vals[2][1]= d[2][0] * multiplier.d[0][1] +
      d[2][1] * multiplier.d[1][1] + d[2][2] * multiplier.d[2][1] + d[2][3] * multiplier.d[3][1];
    vals[2][2]= d[2][0] * multiplier.d[0][2] +
      d[2][1] * multiplier.d[1][2] + d[2][2] * multiplier.d[2][2] + d[2][3] * multiplier.d[3][2];
    vals[2][3]= d[2][0] * multiplier.d[0][3] +
      d[2][1] * multiplier.d[1][3] + d[2][2] * multiplier.d[2][3] + d[2][3] * multiplier.d[3][3];
    vals[3][0]= d[3][0] * multiplier.d[0][0] +
      d[3][1] * multiplier.d[1][0] + d[3][2] * multiplier.d[2][0] + d[3][3] * multiplier.d[3][0];
    vals[3][1]= d[3][0] * multiplier.d[0][1] +
      d[3][1] * multiplier.d[1][1] + d[3][2] * multiplier.d[2][1] + d[3][3] * multiplier.d[3][1];
    vals[3][2]= d[3][0] * multiplier.d[0][2] +
      d[3][1] * multiplier.d[1][2] + d[3][2] * multiplier.d[2][2] + d[3][3] * multiplier.d[3][2];
    vals[3][3]= d[3][0] * multiplier.d[0][3] +
      d[3][1] * multiplier.d[1][3] + d[3][2] * multiplier.d[2][3] + d[3][3] * multiplier.d[3][3];
    Matrix4x4 result(vals[0][0], vals[0][1], vals[0][2], vals[0][3],
		     vals[1][0], vals[1][1], vals[1][2], vals[1][3],
		     vals[2][0], vals[2][1], vals[2][2], vals[2][3],
		     vals[3][0], vals[3][1], vals[3][2], vals[3][3]);
    return result;

  }

  const Vector3D Matrix4x4::multVector(const Vector3D &v, const double w) const {
    return Vector3D(v[0]*w, v[1]*w, v[2]*w);
  }

  double Matrix4x4::determinant() const {
    Matrix3x3 _minus00(d[1][1], d[1][2], d[1][3],
		       d[2][1], d[2][2], d[2][3],
		       d[3][1], d[3][2], d[3][3]);

    Matrix3x3 _minus01(d[1][0], d[1][2], d[1][3],
		       d[2][0], d[2][2], d[2][3],
		       d[3][0], d[3][2], d[3][3]);

    Matrix3x3 _minus02(d[1][0], d[1][1], d[1][3],
		       d[2][0], d[2][1], d[2][3],
		       d[3][0], d[3][1], d[3][3]);

    Matrix3x3 _minus03(d[1][0], d[1][1], d[1][2],
		       d[2][0], d[2][1], d[2][2],
		       d[3][0], d[3][1], d[3][2]);

    double det;
    det = d[0][0] * _minus00.determinant() - d[0][1] * _minus01.determinant() +
      d[0][2] * _minus02.determinant() - d[0][3] * _minus03.determinant();
    return det;
  }

  /*
   * The cofactor of the matrix from the 1-indexed location d[i][j]
   */
  double Matrix4x4::cofactor(int i, int j) const{
    // algorithm from http://en.wikipedia.org/wiki/Minor_(linear_algebra)
    // int iactual = max(0, i-1);
    // int jactual = max(0, j-1);

    // Matrix3x3 minor;
    // double minor[3][3];


    // for(int idx = 0; idx < 4; idx++){
    //   if(idx != iactual){ // skip the 'i' row
    // 	for(int jdx = 0; jdx < 4; jdx ++){
    // 	  if(jdx != jactual){//skip the 'j' column
    // 	    minor[idx][jdx] =
    // 	  }
    // 	}
    //   }
    // }

    // // int iactual = i;
    // // int jactual = j;

    // double cofij = pow(-1, iactual + jactual) * d[iactual][jactual];
    // return cofij;
    return 0;
  }


}
