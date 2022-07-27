cmake_minimum_required(VERSION 3.15)
project(dotman VERSION 0.1 LANGUAGES CXX)

#if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings")
  set(CMAKE_CXX_FLAGS "-O0 -g -Wall -fprofile-arcs -ftest-coverage")
#  set(CMAKE_CXX_FLAGS_RELEASE "-03")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverag#e")	
#endif()

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/dotman.dir)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(SOURCES main.cc)

add_executable(dotman ${SOURCES})

add_custom_target(gcov	
  COMMAND mkdir -p coverage
  COMMAND ${CMAKE_MAKE_PROGRAM} test
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  
add_custom_command(TARGET gcov
  COMMAND echo "============= GCOV ============"
  COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cc -o ${OBJECT_DIR} | grep -A 5 "gropdot/include" > CoverageSummary.tmp
  COMMAND cat CoverageSummary.tmp
  COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage)

add_dependencies(gcov dotman)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FIELS CTestTestfile.cmake)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES cmake_install.cmake)

add_custom_target(scrub
COMMAND ${CMAKE_MAKE_PROGRAM} clean
COMMAND rm -f ${OBJECT_DIR}/*.gcno
COMMAND rm -f ${OBJECT_DIR}/*.gcda
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

#For when i wanna, this is below as an example for testing output.
enable_testing()

add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/dotman)
#set_tests_properties(output_test PROPERTIES PASS_REGULAR_EXPRESSION "0;5;10")


