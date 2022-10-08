include( FindCPPUNIT )

# download & build cppunit
if( NOT CPPUNIT_FOUND )

   configure_file( ${CMAKE_MODULE_PATH}/DownloadCPPUNIT.cmake.in ${CMAKE_BINARY_DIR}/cppunit-download/CMakeLists.txt )
   
   MESSAGE(STATUS "Downloading CppUnit")   
   execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppunit-download )
     
   execute_process(COMMAND ${CMAKE_COMMAND} --build . 
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppunit-download )
   
   MESSAGE(STATUS "cmake CppUnit for ${CMAKE_GENERATOR}")      
   execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppunit-src)
   
   IF(${CMAKE_GENERATOR} MATCHES "Visual Studio")
     MESSAGE(STATUS "Build debug version of CppUnit")     
     execute_process(COMMAND ${CMAKE_COMMAND} --build . --target cppunit --config Debug
       WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppunit-src )
   ENDIF(${CMAKE_GENERATOR} MATCHES "Visual Studio")
   
   MESSAGE(STATUS "Build release version of CppUnit")        
   execute_process(COMMAND ${CMAKE_COMMAND} --build . --target cppunit --config Release
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppunit-src )
 
   add_subdirectory(${CMAKE_BINARY_DIR}/cppunit-src ${CMAKE_BINARY_DIR}/cppunit-build)

endif(NOT CPPUNIT_FOUND)

# compile test cases
include( FindCPPUNIT )

include( FindCPPUNIT )

if( CPPUNIT_FOUND )

   ## setup
   include(CTest)
   include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/test"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Password"
        "${CPPUNIT_INCLUDE_DIR}"
    )
    MESSAGE( STATUS "Generated with config types : ${CMAKE_CONFIGURATION_TYPES}")
    MESSAGE( STATUS "                 Build Type : ${CMAKE_BUILD_TYPE}" )
    MESSAGE( STATUS "            CppUnit library : ${CPPUNIT_LIBRARIES}" )
    MESSAGE( STATUS "      CppUnit Debug library : ${CPPUNIT_DEBUG_LIBRARY}" )
    MESSAGE( STATUS "         Cpp compiler flags : ${CMAKE_CXX_FLAGS}" )    

    add_executable(test_password test_password.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../src/Password/Password.cpp )
    target_link_libraries( test_password optimized ${CPPUNIT_LIBRARY} debug ${CPPUNIT_DEBUG_LIBRARY} )
    add_test( NAME test_password COMMAND test_password WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

else( CPPUNIT_FOUND )
    MESSAGE(SEND_ERROR "Could not find CppUnit library ...")
endif( CPPUNIT_FOUND )

