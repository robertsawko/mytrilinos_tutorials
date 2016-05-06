#include <Teuchos_CommandLineProcessor.hpp>

int
main (int argc, char *argv[])
{
  using std::cout;
  using std::endl;
  Teuchos::CommandLineProcessor clp;

  int iterations = 10;
  clp.setOption("iterations", &iterations, "Number of iterations");
  // Parsing will throw an exception in order to suppress an execution of the
  // code. TODO: Investigate if there's a cleaner way of doing it.
  clp.parse(argc, argv);

  while(--iterations)
      cout << "What-ho!" << endl;
  return 0;
}
