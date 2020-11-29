cmake_minimum_required(VERSION 3.17)
project(pronounceable_pwd)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/core)
include_directories(src/Password)

add_executable(pronounceable_pwd
        src/core/application.cpp
        src/core/application.h
        src/Password/Password.cpp
        src/Password/Password.h
        src/Password/Password_test.cpp
        src/main.cpp
        src/utils.cpp
        src/utils.h
        version.h)
