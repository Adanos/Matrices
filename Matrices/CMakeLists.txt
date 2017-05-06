project(Matrices)
cmake_minimum_required(VERSION 2.8)
include_directories(AlgorithmMultiplication)
aux_source_directory(. SRC_LIST)
aux_source_directory(./AlgorithmMultiplication SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})



