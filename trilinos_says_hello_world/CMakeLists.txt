cmake_minimum_required(VERSION 2.7)

FIND_PACKAGE(Trilinos REQUIRED 
  PATHS /home/robert/trilinos12.6/usr/local/lib/cmake/Trilinos
  COMPONENTS Tpetra) # Note: COMPONENTS option will construct a minimal(?) list
                     # of necessary packages to link a specific package.

include_directories(${Trilinos_INCLUDE_DIRS})
link_directories(${Trilinos_LIBRARY_DIRS})

add_definitions(-std=c++11)

add_executable(
  hello_world
  hello_world.cpp 
)

target_link_libraries(hello_world ${Trilinos_LIBRARIES})
