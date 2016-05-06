cmake_minimum_required(VERSION 2.7)

set(
  Trilinos_DIR
  "/usr/local/lib/cmake/Trilinos" # Note lib/cmake/Trilinos suffix
  CACHE PATH "Provide path to Trilinos cmake files") 

FIND_PACKAGE(Trilinos REQUIRED 
  PATHS ${Trilinos_DIR}
  COMPONENTS Teuchos) 

include_directories(${Trilinos_INCLUDE_DIRS})
link_directories(${Trilinos_LIBRARY_DIRS})

add_definitions(-std=c++11)

add_executable(
  ref_count
  ref_count.cpp 
)

add_executable(
  clp
  clp.cpp 
)

target_link_libraries(ref_count ${Trilinos_LIBRARIES})
target_link_libraries(clp ${Trilinos_LIBRARIES})
