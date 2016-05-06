/*!
\example hello_world.cpp
\brief Initialization example for integrating Tpetra into an existing non-MPI application.

*/

// ... Your other include files go here ...
#include <Tpetra_DefaultPlatform.hpp>
#include <Teuchos_DefaultSerialComm.hpp>
#include <Tpetra_Version.hpp>
#include <Teuchos_oblackholestream.hpp>

// Do something with the given communicator.  In this case, we just
// print Tpetra's version to stdout on Process 0.
void
exampleRoutine (const Teuchos::RCP<const Teuchos::Comm<int> >& comm)
{
  if (comm->getRank () == 0) {
    // On Process 0, print out the Tpetra software version.
    std::cout << Tpetra::version () << std::endl << std::endl;
  }
}

int
main (int argc, char *argv[])
{
  using std::cout;
  using std::endl;
  using Teuchos::Comm;
  using Teuchos::SerialComm;
  using Teuchos::RCP;
  using Teuchos::rcp;

  // Make a "serial" (non-MPI) communicator.
  // It doesn't actually "communicate," because it only has one process.
  RCP<const Comm<int> > comm (new SerialComm<int> ());

  // With a "serial" communicator, the rank is always 0,
  // and the number of processes is always 1.
  const int myRank = comm->getRank ();
  const int numProcs = comm->getSize ();

  if (myRank == 0) {
    cout << "Total number of processes: " << numProcs << endl;
  }

  // Test the two assertions in the previous comment.
  // TEUCHOS_TEST_FOR_EXCEPTION is a macro defined in the Teuchos
  // package that takes three arguments: a bool expression, an
  // exception to throw if the expression evaluates to true, and a
  // message (interpreted as if it follows a "<<" after an
  // std::ostream) to include in the exception.  The macro includes
  // useful line number and file information in the exception message,
  // as well as a place where you can set a breakpoint in a debugger
  // right before the exception is thrown.

  TEUCHOS_TEST_FOR_EXCEPTION(
    myRank != 0, std::logic_error,
    "This is a serial (non-MPI) example, but the rank of the calling process "
    "the Teuchos::Comm is " << myRank << " != 0.  Please report this bug.");

  TEUCHOS_TEST_FOR_EXCEPTION(
    numProcs != 1, std::logic_error,
    "This is a serial (non-MPI) example, but the number of processes in "
    "the Teuchos::Comm is " << numProcs << " != 1.  Please report this bug.");

  // Do something with the new communicator.
  exampleRoutine (comm);

  // This tells the Trilinos test framework that the test passed.
  if (myRank == 0) {
    cout << "End Result: TEST PASSED" << endl;
  }

  return 0;
}
