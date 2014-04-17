

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
  }

  void Rasterizer::render() {
    png::image<png::rgb_pixel> image_data(m_width, m_height);
    Vector3D color;

    Matrix4x4 transform_matrix = generateTransform();

    Triangle *cur_triangle;
    for(int i = 0; i < m_triangles.size(); i++) {
      cur_triangle = &m_triangles[i];
      //NEXT STEP
      need to multiply all vertices in triangle by transform_matrix;
      put results into fragment array?;
      //NEXT STEP

    }

    // image_data[y][x] = png::rgb_pixel(color[0] * 255, color[1] * 255,
    // 				     color[2] * 255);
    //image_data.write(m_outputFileName);
  }

  Matrix4x4 Rasterizer::generateTransform() {
    Matrix4x4 matr;
    matr.setIdentity();

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
