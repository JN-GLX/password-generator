cmake_minimum_required(VERSION 3.17)
project(pronounceable_pwd)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Release)

include_directories(.)
include_directories(src)
include_directories(src/core)
include_directories(src/Password)

add_subdirectory(test)

enable_testing()

add_executable(pwgen
        src/core/application.cpp
        src/core/application.h
        src/core/helpers.h
        src/core/helpers.cpp
        src/Password/Password.cpp
        src/Password/Password.h
        src/main.cpp
        version.h)

install(TARGETS pwgen DESTINATION bin)
