cmake_minimum_required(VERSION 3.17)
project(pronounceable_pwd)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_BUILD_TYPE Release)

include_directories(.)
include_directories(src)
include_directories(src/core)
include_directories(src/Password)
include_directories(src/Engine)

add_subdirectory(test)

# download gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/bb9216085fbbf193408653ced9e73c61e7766e80.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(pwgen
        src/core/application.cpp
        src/core/application.h
        src/core/helpers.h
        src/core/helpers.cpp
        src/Password/Password.cpp
        src/Password/Password.h
        src/Engine/Engine.cpp
        src/Engine/Engine.h
        src/main.cpp
        version.h)

target_include_directories(pwgen PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

install(TARGETS pwgen DESTINATION bin)
