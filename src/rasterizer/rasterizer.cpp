

#include "rasterizer.h"

namespace rasterizer {
  const double FAR_PLANE_DISTANCE = 200.0;

  Rasterizer::Rasterizer(){}

  Rasterizer::Rasterizer(raytracer::Scene *scene, GraphicsArgs args){
    m_triangles = scene->getTriangles();
    m_camera = scene->cameraList[0];
    this->m_width =  args.width;
    this->m_height = args.height;
    this->m_outputFileName = args.outputFileName;
    this->m_focal_length = args.depthOfFieldDistance;
    if(m_focal_length == 0){
      m_focal_length = 1.0;
    }
  }

  void Rasterizer::render() {
    png::image<png::rgb_pixel> image_data(m_width, m_height);

    // Set background color
    Vector3D backgroundColor(0.3,0.3,0.3);
    for (size_t y = 0.0; y < image_data.get_height(); ++y) {
      for (size_t x = 0.0; x < image_data.get_width(); ++x) {
	image_data[y][x] = png::rgb_pixel(backgroundColor[0] * 255, backgroundColor[1] * 255,
					  backgroundColor[2] * 255);
      }
    }
    Matrix4x4 transform_matrix = generateTransform();

    cout << "transform_matrix.print() :" << endl;
    transform_matrix.print();
    Triangle *cur_triangle;
    for(int i = 0; i < m_triangles.size(); i++) {
      cur_triangle = &m_triangles[i];
      transform_verts(cur_triangle, transform_matrix);

      //cout << "cur_triangle->getP1() :" << cur_triangle->getP1() << endl;

      double minX = std::min(cur_triangle->getP1()[0], cur_triangle->getP2()[0]);
      minX = std::min(minX, cur_triangle->getP3()[0]);
      double minY = std::min(cur_triangle->getP1()[1], cur_triangle->getP2()[1]);
      minY = std::min(minY, cur_triangle->getP3()[1]);

      double maxX = std::max(cur_triangle->getP1()[0], cur_triangle->getP2()[0]);
      maxX = std::max(maxX, cur_triangle->getP3()[0]);
      double maxY = std::max(cur_triangle->getP1()[1], cur_triangle->getP2()[1]);
      maxY = std::max(maxY, cur_triangle->getP3()[1]);

      // cout << "miny :" << miny << endl;

      // cout << "minX :" << minX << endl;

      // cout << "maxX :" << maxX << endl;

      // cout << "maxY :" << maxY << endl;


      Vector3D color;
      for(int y = minY; y < std::min(maxY, (double)image_data.get_height()); y++){
	for(int x = minX; x < std::min(maxX, (double)image_data.get_width()); x++ ){
	  if(x <= image_data.get_width() && y <= image_data.get_height() && x >= 0 && y >= 0) {

	    if(isInTriangle(x, y, cur_triangle)) {
	      //cout << "in triangle!\n";
	      color = computeColor(x, y, cur_triangle);

	      try{
		image_data[y][x] = png::rgb_pixel(color[0] * 255, color[1] * 255,
						color[2] * 255);
	      } catch(...){
		cout << "x,y :" << x << "," << y << endl;
		cout << "width, height: " << image_data.get_width() <<","<< image_data.get_height() << endl;
	      }
	    }
	  } else {
	    // the pixel/point is outside the viewplane.
	    //cout << "clipped\n";
	  }
	}
      }
    }
    image_data.write(m_outputFileName);
  }

  bool Rasterizer::isInTriangle(int x, int y, Triangle *tri){

    Vector3D v0 = tri->getP3() - tri->getP1();
    Vector3D v1 = tri->getP2() - tri->getP1();
    Vector3D p(x, y, 1.0);
    Vector3D v2 = p - tri->getP1();
    //double alpha, beta, gamma;


    v0.set(v0[0], v0[1], 1.0);
    v1.set(v1[0], v1[1], 1.0);
    v2.set(v2[0], v2[1], 1.0);

    double dot00 = v0.dot(v0);
    double dot01 = v0.dot(v1);
    double dot02 = v0.dot(v2);
    double dot11 = v1.dot(v1);
    double dot12 = v1.dot(v2);

    double inverseDenom = 1.0 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * inverseDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * inverseDenom;
    return (u >= 0) && (v >= 0) && (u + v < 1);
    //return true;
  }

  Vector3D Rasterizer::computeColor(int x, int y, Triangle *tri){
    Vector3D color(0, 0, 0.5);
    return color;
  }

  void Rasterizer::transform_verts(Triangle *tri, Matrix4x4 transform) {
    double w = 1.0;
    //for each vertice, multiply by transform
    Vector3D p1 = tri->getP1();
    Vector3D p2 = tri->getP2();
    Vector3D p3 = tri->getP3();

    tri->setP1(transform.multVector(p1, w));
    tri->setP2(transform.multVector(p2, w));
    tri->setP3(transform.multVector(p3, w));
  }

  Matrix4x4 Rasterizer::generateTransform() {
    Matrix4x4 matr;
    matr.setIdentity();

    matr.print();

    Matrix4x4 viewPortMatrix = matr.createViewPortMatrix(m_height, m_width);

    Vector3D eye = m_camera->location;
    double near_plane = -m_focal_length;
    double far_plane = -FAR_PLANE_DISTANCE;
    double top, bottom, left, right;
    top = m_height / 2.0;
    bottom = -top;
    right = m_width / 2.0;
    left = -right;

    Matrix4x4 ortho_matrix = matr.createOrthoMatrix(near_plane, far_plane,
						    left, right, top, bottom);

    cout << "ortho matrix\n";
    ortho_matrix.print();
    Basis basis = m_camera->orthoBasis;
    Matrix4x4 camera_matrix = matr.createCameraMatrix(basis.U, basis.V, basis.W,
						      m_camera->location);

    Matrix4x4 perspective_matrix;
    perspective_matrix = matr.createPerspectiveMatrix(near_plane, far_plane,
						      ortho_matrix);
    matr = viewPortMatrix * perspective_matrix * camera_matrix;
    return matr;
  }



} /** end  rasterizer*/
