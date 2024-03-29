enable_testing()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Password"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine"
)

add_executable(ApplicationTest ApplicationTest.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/application.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/application.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/Engine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/Engine.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/AlphaNumEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/StandardEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/PronounceableEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/NumericEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/randomutils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/randomutils.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/helpers.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/helpers.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/stringutils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/stringutils.cpp
)

add_executable(PasswordTest PasswordTest.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/Engine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/Engine.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/AlphaNumEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/StandardEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/PronounceableEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/NumericEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/randomutils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/randomutils.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/stringutils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/stringutils.cpp
)

add_executable(EngineTest EngineTest.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/Engine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/Engine.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/AlphaNumEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/StandardEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/PronounceableEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/NumericEngine.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/randomutils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/randomutils.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/stringutils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/Engine/stringutils.cpp
)

target_link_libraries(PasswordTest gtest_main)

target_link_libraries(EngineTest gtest_main)

target_link_libraries(ApplicationTest gtest_main)

include(GoogleTest)
gtest_discover_tests(PasswordTest)
gtest_discover_tests(EngineTest)
gtest_discover_tests(ApplicationTest)
