cmake_minimum_required (VERSION 3.11)
project ("brainfuck_interpreter")
add_executable(${PROJECT_NAME} src/main.cpp src/interpreter.h)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)