cmake_minimum_required(VERSION 2.8)
project(testrunner)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(testrunner ./tests/Test.cpp ./tests/TestRunner.cpp)
