enable_testing()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Password"
)

add_executable(PasswordTest PasswordTest.cpp 
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.h
)

target_link_libraries(PasswordTest gtest_main)

include(GoogleTest)
gtest_discover_tests(PasswordTest)
