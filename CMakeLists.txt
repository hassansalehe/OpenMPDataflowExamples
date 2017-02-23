cmake_minimum_required (VERSION 2.6)
set(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -g")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fopenmp -g")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fopenmp -g")

#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
#SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fopenmp")
#SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fopenmp")
#set(CMAKE_CXX_DEFINES "${CMAKE_CXX_DEFINES} -fopenmp")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fopenmp" )
set(USE_INTERMEDIATE_OBJECTS_TARGET off)

project (OpenMPDataflowExamples)
add_definitions(-fopenmp)
set(CMAKE_CXX_COMPILER "clang-archer++")

# examples
add_executable(BankingTaskRacy   src/BankingTaskRacy.cpp)
add_executable(BankingTaskSerial src/BankingTaskSerial.cpp)
add_executable(Counters          src/Counters.cpp)
add_executable(MapReduce         src/MapReduce.cpp)

# progam output checker
add_executable(CheckOutput       src/CheckOutput.cpp)
