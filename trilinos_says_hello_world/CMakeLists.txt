cmake_minimum_required(VERSION 2.7)

set( # This allows the user to specify where Trilinos lives. 
  Trilinos_DIR
  "/usr/local/lib/cmake/Trilinos" # Note lib/cmake/Trilinos suffix
  CACHE PATH "Provide path to Trilinos cmake files") 

FIND_PACKAGE(Trilinos REQUIRED 
  PATHS ${Trilinos_DIR}
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
