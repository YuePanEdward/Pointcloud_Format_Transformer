#include <boost/program_options.hpp>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/io.h>
#include <pcl/io/vtk_io.h>
 
#include <iostream>
#include <fstream>
 
using namespace pcl;
using namespace std;
 
int main(int argc, char **argv){
	
    ///The file to read from.
	string infile;
 
	///The file to output to.
	string outfile;
 
    // if (argc!=3)
    // {
    //     cout<<"Input ERROR"<<endl;
    //     return 0;
    // }
    // else
    // {
        infile=argv[1];
        outfile=argv[2];
    //}
    
	// load point cloud
	fstream input(infile.c_str(), ios::in | ios::binary);
	if(!input.good()){
		cerr << "Could not read file: " << infile << endl;
		exit(EXIT_FAILURE);
	}
	input.seekg(0, ios::beg);
 
	pcl::PointCloud<PointXYZI>::Ptr points (new pcl::PointCloud<PointXYZI>);
 
	int i;
	for (i=0; input.good() && !input.eof(); i++) {
		PointXYZI point;
		input.read((char *) &point.x, 3*sizeof(float));
		input.read((char *) &point.intensity, sizeof(float));
        point.intensity*=255;
		points->push_back(point);
	}
	input.close();
 
	cout << "Read bin file from [" << infile << "]: "<< i << " points, writing to [" << outfile << "]"<< endl;
    
    if (pcl::io::savePCDFileBinary(outfile, *points) == -1) 
	{
		PCL_ERROR("Couldn't write file\n");
		return false;
	}
}
