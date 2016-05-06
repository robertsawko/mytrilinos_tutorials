cmake_minimum_required(VERSION 2.7)

set( # This allows the user to specify where Trilinos lives. 
  Trilinos_DIR
  "/usr/local/lib/cmake/Trilinos" # Note lib/cmake/Trilinos suffix
  CACHE PATH "Provide path to Trilinos cmake files") 

FIND_PACKAGE(Trilinos REQUIRED 
  PATHS ${Trilinos_DIR}
  COMPONENTS Tpetra)

include_directories(${Trilinos_INCLUDE_DIRS})
link_directories(${Trilinos_LIBRARY_DIRS})

add_definitions(-std=c++11)

add_executable(
  01_init
  01_init.cpp 
)

add_executable(
  02_map+vector
  02_map+vector.cpp 
)

target_link_libraries(01_init ${Trilinos_LIBRARIES})
target_link_libraries(02_map+vector ${Trilinos_LIBRARIES})
