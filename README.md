# Continuous Time Recurrent Neural Network Benchmark

This repository contains code for the reachability analyis of Continuous Time Recurrent Neural Networks (CTRNN) used to approximate dynamical systems.
It contains:
1. Matlab Files that simulate the trajectories of the Networks and the systems they approximate.
2. Simulink Stateflow Model of all systems
3. Benchmark Generators for reachability tools 
4. Paper Descrbing reachability analysis of CTRNNs


### How do I get set up? ###

In order to generate the SpaceEx Models:
1. Download the latest version of Hyst located here: [Hyst](https://github.com/verivital/hyst)
2. Navigate to the GenerateSpaceExModels directory
3. Edit the java path in generateFPANN.m and generateDPCTRNN to wherever you stored hyst and run those scripts.

### Who do I talk to? ###

For any questions please contact:
1. patrick.musau@vanderbilt.edu
