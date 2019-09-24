#include <boost/program_options.hpp>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/io.h>
#include <pcl/io/vtk_io.h>
 
#include <iostream>
#include <fstream>
 
using namespace pcl;
using namespace std;


// Brief: Do the batch csv2pcd transformation for eth point cloud registration dataset(https://projects.asl.ethz.ch/datasets/doku.php?id=laserregistration:laserregistration)

// Delete invalid characters such as spaces, tabs, etc. in strings
string Trim(string& str)
{
	str.erase(0,str.find_first_not_of(" \t\r\n"));
	str.erase(str.find_last_not_of(" \t\r\n") + 1);
	return str;
}

int main(int argc, char **argv){
	
    // The file to read from.
	string infile = argv[1];
 
	// The file to output to.
	string outfile = argv[2];
    
    std::cout<<"Transform begin"<<std::endl;

    ifstream fin(infile); // Open the file
    
	std::string line; 

    getline(fin, line);
	
    float  x_p = 0, y_p = 0, z_p = 0, i_p = 0;
    int i=0;
    
    pcl::PointCloud<PointXYZ>::Ptr pointCloud (new pcl::PointCloud<PointXYZ>);

    while (getline(fin, line))   // The entire line is read, the newline character "\n" is distinguished
	{
		istringstream sin(line); // Read the entire line string into the string stream
		std::vector<std::string> point_datastrings; 
		std::string point_datastring;
		
        while (getline(sin, point_datastring, ',')) // Use the ',' as the dividing marker, get
		{
			point_datastrings.push_back(point_datastring); // Add those isolated string into the vector
		}
		x_p = atof(Trim(point_datastrings[1]).c_str());  //x
		y_p = atof(Trim(point_datastrings[2]).c_str());  //y
		z_p = atof(Trim(point_datastrings[3]).c_str());  //z
        
        pcl::PointXYZ Pt;
		Pt.x = x_p;
		Pt.y = y_p;
		Pt.z = z_p;
		pointCloud->points.push_back(Pt);
		
        //std::cout <<"Point："<< i << "\t" << x_p << "\t" << y_p <<  "\t" << z_p << std::endl; 
        i++;
	}

	fin.close();
 
	cout << "Read csv file from [" << infile << "]: "<< i << " points, writing to [" << outfile << "]"<< endl;
    
    if (pcl::io::savePCDFileBinary(outfile, *pointCloud) == -1) 
	{
		PCL_ERROR("Couldn't write file\n");
		return false;
	}

	std::cout<<"Transform done"<<std::endl;
}