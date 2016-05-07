#include <Tpetra_DefaultPlatform.hpp>

int main(int argc, char *argv[]) {
  using Teuchos::rcp;
  using Teuchos::Comm;
  using Teuchos::SerialComm;
  Teuchos::RCP<const Comm<int>> comm = rcp(new SerialComm<int>());

  const int myRank = comm->getRank();
  const int numProcs = comm->getSize();
  if (myRank == 0) {
    std::cout << "Total number of processes: " << numProcs << std::endl;
  }
  return 0;
}
