#include <Teuchos_RCP.hpp>

class A{};

int
main (int argc, char *argv[])
{
  using std::cout;
  using std::endl;
  using Teuchos::RCP;

  RCP<A> a = RCP<A>(new A());
  RCP<A> b = a;
  cout << "There are " << b.total_count() << " references." << endl;
  return 0;
}
