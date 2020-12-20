#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PTree.hpp"

using namespace std;
using namespace sf;

int main( int argc, char* argv[])
{
  double L = 0.0; // Length of square sides
  int N = 0; // Number of times to call recursive function

  L = atol(argv[1]);
  N = atoi(argv[2]);
  sf::Vector2f vPoint;
  vPoint.x = 0;
  vPoint.y = 0;

  // Create and Display Window
  PTree tree(L, N);
  return 0;
}
