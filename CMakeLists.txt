cmake_minimum_required(VERSION 2.8.3)
project(kitti_velodyne) 
 
add_compile_options(-std=c++11)
 
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(PCL 1.7 REQUIRED)
 
include_directories(
 include
)

link_directories(${PCL_LIBRARY_DIRS})
 
add_executable(bin2pcd src/bin2pcd.cpp)   
  
target_link_libraries(bin2pcd
  ${PCL_LIBRARIES}
)

add_executable(csv2pcd src/csv2pcd.cpp)   
  
target_link_libraries(csv2pcd
  ${PCL_LIBRARIES}
)

add_executable(ply2pcd src/ply2pcd.cpp)   
  
target_link_libraries(ply2pcd
  ${PCL_LIBRARIES}
)