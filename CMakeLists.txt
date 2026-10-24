cmake_minimum_required(VERSION 3.16)

project(class_03)

include_directories(./include)

add_executable(cmake_learn_1 ./src/MarkerManager.cpp ./main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

