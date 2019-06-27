cmake_minimum_required(VERSION 3.14)
project(LSTM)

set(CMAKE_CXX_STANDARD 11)

add_executable(LSTM main.cpp sigmoid.cpp sigmoid.h lstm.cpp lstm.h)