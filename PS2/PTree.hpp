#ifndef PTREE_HPP_INCLUDED
#define PTREE_HPP_INCLUDED

using namespace std;
using namespace sf;

class PTree
{
public:
    PTree(double L, int N);
    ~PTree();

    void pTree(double L, int N, Vector2f vPoint, Vector2f vOrigin, float rotation);
  // Using two overloaded functions, one to draw the tree, another to branch out to two sides
  void drawPtree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent);
  void drawPtree(sf::RenderTarget& target, const float L, const int N);
  
private:
    float width = 0.0;
    float height = 0.0;
    int Xorigin = 0;
    int Yorigin = 0;
    float rotation = 0.0;
    int angle1 = 0;
    int angle2 = 0;
    sf::RenderWindow window;
};

#endif // PTREE_HPP_INCLUDED
