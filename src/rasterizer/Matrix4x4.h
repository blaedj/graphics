#ifndef __MATRIX4x4_H__
#define __MATRIX4x4_H__ 1

#include "Vector3D.h"
using namespace sivelab;
using namespace std;

namespace rasterizer {


  class Matrix3x3
  {
  public:
    double d[3][3];
    double determinant(void) const{

      return d[0][0] * (d[1][1] * d[2][2] - d[1][2] * d[2][1]) -
	d[0][1] * (d[1][0] * d[2][2] - d[1][2] * d[2][0]) +
	d[0][2] * (d[1][0] * d[2][1] - d[1][1] * d[2][0]);
    };

    Matrix3x3(const double a11, const double a12, const double a13,
	     const double a21, const double a22, const double a23,
	      const double a31, const double a32, const double a33) {
      set(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    }


    void set(const double a11, const double a12, const double a13,
	     const double a21, const double a22, const double a23,
	     const double a31, const double a32, const double a33) {
      d[0][0] = a11;
      d[0][1] = a12;
      d[0][2] = a13;

      d[1][0] = a21;
      d[1][1] = a22;
      d[1][2] = a23;

      d[2][0] = a31;
      d[2][1] = a32;
      d[2][2] = a33;
    }

  };

  class Matrix4x4
  {
  public:
    double d[4][4];

    Matrix4x4(); //DONE
    Matrix4x4(const double a11, const double a12, const double a13, const double a14,
	      const double a21, const double a22, const double a23, const double a24,
	      const double a31, const double a32, const double a33, const double a34,
	      const double a41, const double a42, const double a43, const double a44);
    //DONE

    void set(const double, const double, const double, const double,
	     const double, const double, const double, const double,
	     const double, const double, const double, const double,
	     const double, const double, const double, const double);//DONE

    void print(); //DONE

    void setIdentity(void);//DONE

    const Matrix4x4 operator*(const Matrix4x4 &) const;//DONE

    const sivelab::Vector3D multVector(const sivelab::Vector3D &v, const double w) const;//DONE

    double determinant(void) const;//DONE

    double cofactor(int i, int j) const;//TODO

    const Matrix4x4 inverse(void) const;//TODO

    const Matrix4x4 transpose(void) const;       // return the transpose of self

    void makeTranslation(const double x, const double y, const double z);//TODO
    void makeScale(const double x, const double y, const double z);//TODO

    void makeRotationX( const double angle_in_radians );//TODO
    void makeRotationY( const double angle_in_radians );//TODO
    void makeRotationZ( const double angle_in_radians );//TODO

    const Matrix4x4 createCameraMatrix(Vector3D U, Vector3D V, Vector3D W, Vector3D camOrigin);
    const Matrix4x4 createOrthoMatrix(double near_bound, double far_bound,
				      double left_bound, double right_bound,
				      double top_bound, double bottom_bound);
    const Matrix4x4 createViewPortMatrix(int height, int width);

    const Matrix4x4 createPerspectiveMatrix(double near, double far, Matrix4x4 ortho);

  };

  inline const Matrix4x4 operator*(const Matrix4x4& m, const double c)
  {
    return Matrix4x4(m.d[0][0]*c, m.d[0][1]*c, m.d[0][2]*c, m.d[0][3]*c,
		     m.d[1][0]*c, m.d[1][1]*c, m.d[1][2]*c, m.d[1][3]*c,
		     m.d[2][0]*c, m.d[2][1]*c, m.d[2][2]*c, m.d[2][3]*c,
		     m.d[3][0]*c, m.d[3][1]*c, m.d[3][2]*c, m.d[3][3]*c);
  }
}
#endif
