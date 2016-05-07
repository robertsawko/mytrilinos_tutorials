#include <Tpetra_CrsMatrix.hpp>
#include <Tpetra_Map.hpp>
#include <Tpetra_Vector.hpp>
#include <Teuchos_RCP.hpp>

int main(int argc, char *argv[]) {
  using Teuchos::RCP;
  using Teuchos::rcp;
  using Teuchos::Comm;
  using Teuchos::SerialComm;
  using Teuchos::tuple;
  RCP<const Comm<int>> comm = rcp(new SerialComm<int>());

  typedef Tpetra::Vector<>::scalar_type scalar_type;
  typedef Tpetra::Vector<>::local_ordinal_type local_ordinal_type;
  typedef Tpetra::Vector<>::global_ordinal_type global_ordinal_type;

  const Tpetra::global_size_t numGblIndices = 50;

  typedef Tpetra::Map<> map_type;
  RCP<const map_type> map = rcp(new map_type(numGblIndices, // no of elements
                                             0,             // index base
                                             comm));

  typedef Tpetra::CrsMatrix<> crs_matrix_type;
  RCP<crs_matrix_type> A(new crs_matrix_type(map, 0));

  const scalar_type two = static_cast<scalar_type>(2.0);
  const scalar_type negOne = static_cast<scalar_type>(-1.0);
  for (local_ordinal_type lclRow = 0;
       lclRow < static_cast<local_ordinal_type>(map->getNodeNumElements());
       ++lclRow) {
    const global_ordinal_type gblRow = map->getGlobalElement(lclRow);
    // A(0, 0:1) = [2, -1]
    if (gblRow == 0) {
      A->insertGlobalValues(gblRow,
                            tuple<global_ordinal_type>(gblRow, gblRow + 1),
                            tuple<scalar_type>(two, negOne));
    }
    // A(N-1, N-2:N-1) = [-1, 2]
    else if (static_cast<Tpetra::global_size_t>(gblRow) == numGblIndices - 1) {
      A->insertGlobalValues(gblRow,
                            tuple<global_ordinal_type>(gblRow - 1, gblRow),
                            tuple<scalar_type>(negOne, two));
    }
    // A(i, i-1:i+1) = [-1, 2, -1]
    else {
      A->insertGlobalValues(
          gblRow, tuple<global_ordinal_type>(gblRow - 1, gblRow, gblRow + 1),
          tuple<scalar_type>(negOne, two, negOne));
    }
  }
  A->fillComplete();
  std::cout << A->getFrobeniusNorm() << std::endl;
  return 0;
}
