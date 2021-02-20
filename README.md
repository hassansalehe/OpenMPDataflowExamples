# OpenMPDataflowExamples
A repository containing small OpenMP dataflow test examples. Some of these examples are racy. They aim to test the efficiency of Archer, the race detection tool for OpenMP programs.

# How to build and run

## Prerequisites
(1) Archer - to detect data races on these examples, you need ``Archer`` installed on your system. More information on how to install Archer: https://github.com/PRUNERS/archer

(2) CMake - refer to this link on how to install CMake: https://cmake.org/install/

## How to build
First clone the project.

    git clone git@github.com:hassansalehe/OpenMPDataflowExamples.git

and build with the following commands

    cd OpenMPDataflowExamples
    mkdir build && cd build
    cmake ..
    make
All the produced programs should be in the `build` directory.

## How to run
To run a particular program:

    ./<program_name>    # e.g ./banking_task_serial


Run the following command to check how the output of a program changes probably due to data races

    ./CheckOutput <program_name> <numer_of_runs> <expected_output>

where

``program_name`` is the name of the program (e.g. ``banking_task_serial``)  
``number_of_runs`` is the number of runs you want the program to be re-run.
The larger the better.  
``expected_output`` is an integer, the expected output of the program.
