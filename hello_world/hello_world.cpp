/*!
\example hello_world.cpp
\brief Tpetra says hello and informs about its version.

*/

#include <Tpetra_Version.hpp>

int
main (int argc, char *argv[])
{
  using std::cout;
  using std::endl;

  cout << Tpetra::version () << std::endl << endl;
  return 0;
}
