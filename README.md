# PointCloud Format Transformer
A Tool for various basic point cloud data format transformation for well-known datasets. 

## Functions
#### 1. [KITTI Odometry Dataset](http://www.cvlibs.net/datasets/kitti/): bin2pcd

#### 2. [ETH ASL Registration Dataset](https://projects.asl.ethz.ch/datasets/doku.php?id=laserregistration:laserregistration): csv2pcd

#### 3. [ETH PRS Registration Dataset](https://prs.igp.ethz.ch/research/completed_projects/automatic_registration_of_point_clouds.html): ply2pcd

## How to use

```
 git clone xxx.git
 mkdir build
 cd build
 cmake ..
 make
 # change the input/output path in script/run_xxx.sh
 sh script/run_xxx.sh
 # done
```


