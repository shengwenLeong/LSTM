cmake_minimum_required(VERSION 3.14)
project(LSTM)

set(CMAKE_CXX_STANDARD 11)

add_executable(LSTM main.cpp sigmoid.cpp sigmoid.h lstm.cpp lstm.h Fixe_Point.cpp Fixe_Point.h template_utils.h)
add_executable(LSTM_Fixed Fixed_main.cpp Fixed_Lstm.cpp Fixed_Lstm.h Fixed_Sigmoid.cpp Fixed_Sigmoid.h Fixe_Point.cpp Fixe_Point.h template_utils.h)