cmake_minimum_required(VERSION 3.15)
project(dotman VERSION 0.1 LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
  set(CMAKE_CXX_FLAGS_RELEASE "-03")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_library(data SHARED
  include/dot.h
  include/dat.cc
)

add_executable(dotman main.cc)
target_link_libraries(dotman data)
