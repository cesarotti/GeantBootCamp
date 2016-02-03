Repo for teaching Geant4

This program is a very basic Geant4 simulation. It was a study conducted by the MMAPS group regarding the spread of energy deposition in cesium iodide crystals. Other folders include examples of other useful and more advanced topics in Geant4. 

Buildscripts

build.sh - compiles & runs the program in interactive mode. Output will be saved in a directory titled the time of day in the folder ./simResults

batch.sh - runs run1.macro  and saves output in a directory titled the time of day in the folder ./batchResults

compile.sh - compiles code only. Intended for running batch mode, in the event that some structural changes means the program has to be recompiled. Does not execute program.