#!/bin/bash
# Run annihilation

#good practice to clear build folder. Careful if macro is saved in here!
rm -rf /home/local1/GeantBootCamp/example01Build/*

cd /home/local1/GeantBootCamp/example01Build #UPDATE TO YOUR OWN PATHWAY 
cmake -DGEANT4_BUILD_MULTITHREADED=ON -DGeant4_DIR=/usr/local/geant4.10.00.p01/lib64/Geant4-10.0.0 /home/local1/GeantBootCamp/example01 #UPDATE TO YOUR OWN PATHWAY
make clean
make -j4

