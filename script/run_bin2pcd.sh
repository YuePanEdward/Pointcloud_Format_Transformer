infolder=/media/edward/BackupPlus/Data/kitti-dataset/sequences/10;
for file in ${infolder}/velodyne/*.bin
do 
	./bin/bin2pcd $file ${infolder}/HDL64/`basename $file .bin`.pcd
done
