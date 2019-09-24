infolder=/media/edward/BackupPlus/Data/ETH_pointcloud_registration/eth_hg/global;
for file in ${infolder}/PointCloud_csv/*.csv
do 
	./bin/csv2pcd $file ${infolder}/PointCloud_pcd/`basename $file .csv`.pcd
done
