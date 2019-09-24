#include <boost/program_options.hpp>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/ply_io.h>

#include <iostream>
#include <fstream>
 
using namespace pcl;
using namespace std;
 
// Brief: Do the batch ply2pcd transformation for eth tls point cloud datatset (https://prs.igp.ethz.ch/research/completed_projects/automatic_registration_of_point_clouds.html)

int main(int argc, char **argv){
	
    // The file to read from.
	string infile = argv[1];
 
	// The file to output to.
	string outfile = argv[2];
    
    std::cout<<"Transform begin"<<std::endl;
    
	// Load point cloud
	pcl::PointCloud<pcl::PointXYZI>::Ptr pointCloud (new pcl::PointCloud<pcl::PointXYZI>);
    
    if (pcl::io::loadPLYFile<pcl::PointXYZI>(infile, *pointCloud) == -1) //* load the file 
	{
		PCL_ERROR("Couldn't read file \n");
		return (-1);
	}
 
	cout << "Read ply file from [" << infile << "]: "<< pointCloud->points.size() << " points, writing to [" << outfile << "]"<< endl;
    
    if (pcl::io::savePCDFileBinary(outfile, *pointCloud) == -1) 
	{
		PCL_ERROR("Couldn't write file\n");
		return false;
	}

    std::cout<<"Transform done"<<std::endl;
}
