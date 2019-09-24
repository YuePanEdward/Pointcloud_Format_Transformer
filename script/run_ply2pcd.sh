infolder=/media/edward/BackupPlus/Data/ETH_registration_TLS/arch;
for file in ${infolder}/PointCloud_ply/*.ply
do 
	./bin/ply2pcd $file ${infolder}/PointCloud_pcd/`basename $file .ply`.pcd
done
