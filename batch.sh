#!/bin/bash
# Run in batch mode
# Run this after compiling Geant4

cd /home/local1/GeantBootCamp/example01Build 
./example01 /home/local1/GeantBootCamp/run1.mac
mkdir ../batchResults
currentfolder=$(date +%Y:%m:%d#%H:%M:%S)
mkdir ../batchResults/$currentfolder
mv *.root ../batchResults/$currentfolder
rm -rf *.root
cd ../batchResults/$currentfolder
hadd complete.root *.root
mkdir threadfiles
mv *.root threadfiles
cd threadfiles
mv complete.root ../