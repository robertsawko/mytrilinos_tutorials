#include <Tpetra_Map.hpp>
#include <Tpetra_Vector.hpp>
#include <Teuchos_RCP.hpp>

int
main (int argc, char *argv[])
{
  using Teuchos::RCP;
  using Teuchos::rcp;
  using Teuchos::Comm;
  using Teuchos::SerialComm;
  RCP<const Comm<int>> comm = rcp(new SerialComm<int>());

  // What is this lot?
  typedef Tpetra::Vector<> vector_type;
  typedef Tpetra::Vector<>::global_ordinal_type global_ordinal_type;
  typedef Tpetra::Map<> map_type;

  const global_ordinal_type indexBase = 0;
  RCP<const map_type> contigMap =
      rcp (new map_type (2, indexBase, comm));
  vector_type x (contigMap);
  x.putScalar(1.0);
  std::cout<< "Norm of x (all entries are 1.0): "
      << x.norm2 () << std::endl;

  return 0;
}
