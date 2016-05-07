#include <Tpetra_Map.hpp>
#include <Tpetra_Vector.hpp>
#include <Teuchos_RCP.hpp>

int main(int argc, char *argv[]) {
  using Teuchos::RCP;
  using Teuchos::rcp;
  using Teuchos::Comm;
  using Teuchos::SerialComm;
  RCP<const Comm<int>> comm = rcp(new SerialComm<int>());

  typedef Tpetra::Map<> map_type; // using empty angle brackets forces
                                  // type deduction

  RCP<const map_type> contigMap =
      rcp(new map_type(2, // no of elements
                       0, // index base (smallest element in the global index
                       comm));
  Tpetra::Vector<> x(contigMap);
  x.replaceGlobalValue(0, 3.0);
  x.replaceGlobalValue(1, 4.0);
  std::cout << "Norm of x: " << x.norm2() << std::endl;

  // I haven't found a better way to output the components. This uses Teuchos
  // FancyOstream object.
  std::ostream &out(std::cout);
  RCP<Teuchos::FancyOStream> fos =
      Teuchos::fancyOStream(Teuchos::rcpFromRef(out));
  x.describe(*fos, Teuchos::VERB_EXTREME);
  *fos << std::endl;
  return 0;
}
