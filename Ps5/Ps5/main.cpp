#include "ed.hpp"
using std::string;
using std::cout;
using std::endl;

int main(int argc, const char* argv[]) {
  sf::Clock clock;
  sf::Time t;

  string string1, string2;
  std::cin >> string1 >> string2;

  ed test(string1, string2);

  int distance = test.optDistance();

  string alignment = test.align();

  cout << "Edit distance = " << distance << endl;
  cout << alignment;

  t = clock.getElapsedTime();
  cout << "Execution time is " << t.asSeconds() << " seconds" << endl;

  return 0;
}
