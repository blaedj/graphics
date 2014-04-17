

#include "rasterizer.h"

namespace rasterizer {

  Rasterizer::Rasterizer(){}

  Rasterizer::Rasterizer(raytracer::Scene *scene, GraphicsArgs args){
    m_triangles = scene->getTriangles();
    m_camera = scene->cameraList[0];
    this->m_width =  args.width;
    this->m_height = args.height;
    this->m_outputFileName = args.outputFileName;
  }

  void Rasterizer::render() {
    //TODO: implement:
    //0) light and shade
    //1) local transforms on vertices -> world space
    //2) Clipping

    int width = 500; //TODO: integrate into scene w/ command line args
    int height = 500;//TODO: integrate into scene w/ command line args
    png::image<png::rgb_pixel> imageData(width, height);
    Vector3D color;

    Triangle *cur_triangle;

    for(int i = 0; i < m_triangles.size(); i++){
      cur_triangle = &m_triangles[i];

      // for(int j = 0; j < VERTICES_PER_TRIANGLE; j++){
      // 	//scaleVertex(cur_triangle);
      // }
    }

    // imageData[y][x] = png::rgb_pixel(color[0] * 255, color[1] * 255,
    // 				     color[2] * 255);
    imageData.write(m_outputFileName);

  }

} /** end  rasterizer*/
