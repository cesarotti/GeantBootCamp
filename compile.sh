#!/bin/bash
# Run annihilation

cd /home/local1/GeantBootCamp/example01batchBuild #UPDATE TO YOUR OWN PATHWAY 
cmake -DGEANT4_BUILD_MULTITHREADED=ON -DGeant4_DIR=/usr/local/geant4.10.00.p01/lib64/Geant4-10.0.0 /home/local1/GeantBootCamp/example01batch #UPDATE TO YOUR OWN PATHWAY
make clean
make -j4
./example01 run1.mac
#mkdir ../batchResults
#currentfolder=$(date +%Y:%m:%d#%H:%M:%S)
#mkdir ../batchResults/$currentfolder
#mv *.root ../batchResults/$currentfolder
#rm -rf *.root
#cd ../batchResults/$currentfolder
#hadd complete.root *.root
#mkdir threadfiles
#mv *.root threadfiles
#cd threadfiles
#mv complete.root ../

