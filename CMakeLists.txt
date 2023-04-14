cmake_minimum_required(VERSION 3.17)
project(password-generator)

set(CMAKE_CXX_STANDARD 17)
#SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
IF(DEFINED CMAKE_BUILD_TYPE AND CMAKE_VERSION VERSION_GREATER "3.17")
  SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
ENDIF()

cmake_policy(SET CMP0135 NEW)

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
        src/Engine/AlphaNumEngine.cpp
        src/Engine/StandardEngine.cpp
        src/Engine/PronounceableEngine.cpp
        src/Engine/NumericEngine.cpp
        src/Engine/randomutils.h
        src/Engine/randomutils.cpp
        src/main.cpp
        version.h)

file(GLOB gcovinfo "*.gcda")
list(REMOVE_ITEM gcovinfo)

target_include_directories(pwgen PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

install(TARGETS pwgen DESTINATION bin)
