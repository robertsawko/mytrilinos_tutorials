cmake_minimum_required(VERSION 2.7)

set( # This allows the user to specify where Trilinos lives. 
  Trilinos_DIR
  "/usr/local/lib/cmake/Trilinos" # Note lib/cmake/Trilinos suffix
  CACHE PATH "Provide path to Trilinos cmake files") 

FIND_PACKAGE(Trilinos REQUIRED 
  PATHS ${Trilinos_DIR}
  COMPONENTS Amesos2)

include_directories(${Trilinos_INCLUDE_DIRS})
link_directories(${Trilinos_LIBRARY_DIRS})

add_definitions(-std=c++11)
include_directories("/usr/include/superlu")

foreach(exe_name IN ITEMS simple_solve)
  add_executable(${exe_name} ${exe_name}.cpp)
  target_link_libraries(${exe_name} ${Trilinos_LIBRARIES})
endforeach(exe_name)
