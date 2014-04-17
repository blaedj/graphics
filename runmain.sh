#!/bin/sh

#./write_images -w 300 -h 300 -i ../src/petesCode/SceneFiles_TestA/oneSphere.xml -o testoutput.png -v

#./write_images -w 300 -h 300 -i ../src/petesCode/SceneFiles_TestA/threeTriangles.xml -o threeTrianglesRayT.png -v

# rm oldPic/simple2SpheresRayT.png
# mv simple2SpheresRayT.png oldPic/

# ./write_images -w 700 -h 700 -i ../src/petesCode/SceneFiles_TestA/simpleTwoSpheres.xml -o simple2SpheresRayT.png -v

# rm oldPic/phongExpRayT.png
# mv phongExpRayT.png oldPic/

# ./write_images -w 700 -h 700 -i ../src/petesCode/SceneFiles_TestA/PhongExp.xml -o phongExpRayT.png -v


##RASTERIZATION
rm oldPic/threeTrianglesRaster.png
mv threeTrianglesRaster.png oldPic/

./write_images -e raster -w 500 -h 500 -i ../src/petesCode/SceneFiles_TestA/threeTriangles.xml -o threeTrianglesRaster.png -v
