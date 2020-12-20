#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <cmath>
#include "PTree.hpp"
#include <iostream>

using namespace std;
using namespace sf;

// Constructor
PTree::PTree(double L, int N)
{
  // Sets the window size by multiplying L
  width = (6 * L);
  height = (4 * L);
  /*
  Vector2f vPoint = {width/2, height - 1};
  Vector2f vOrigin;
  vOrigin.x = L/2;
  vOrigin.y = L;
  Code from my first attempt using ConvexShape*/

  window.create(VideoMode(width, height), "Pythagoras Fractal Tree");
  // Once window is created time to generate the tree
  while(window.isOpen())
  {
    for(sf::Event event; window.pollEvent(event);)
      {
          if(event.type == sf::Event::Closed)
            window.close();
      }
    window.clear(sf::Color::White);
    PTree::drawPtree(window, L, N);
    window.display();
  }
}

// Optimized destructor
PTree::~PTree(){}

/* Originally was going to use the ConvexShape functions to draw the tree, but using rectangles was much easier, I'm keeping the source code here

void PTree::pTree(double L, int N, Vector2f vPoint, Vector2f vOrigin, float rotation)
{
  Vector2f vPointR;

  // Ends recursion once tree is finished
  if(N < 1) return;

  // Define a convex shape called convexSquare
  ConvexShape convexSquare(4);
  convexSquare.setPoint(0, Vector2f(0, 0 ));
  convexSquare.setPoint(1, Vector2f(0, L));
  convexSquare.setPoint(2, Vector2f(L, L));
  convexSquare.setPoint(3, Vector2f(L, 0));

  convexSquare.setOutlineThickness(1.f);
  convexSquare.setFillColor(Color::Black);
  convexSquare.setOutlineColor(Color::White);

  convexSquare.setPosition(vPoint);
  convexSquare.setOrigin(vOrigin);
  convexSquare.setRotation(rotation);

  while(window.isOpen())
  {
    Event event;
    while(window.pollEvent(event))
    {
      if(event.type == Event::Closed)
      {
        window.close();
      }
    }
    if(N >= 0)
    {
    window.draw(convexSquare);
    window.display();
    L = (L * (sqrt(2)/2));
    N = N - 1;
    rotation = rotation - 135;

    // Generate left side
    vPoint = convexSquare.getTransform().transformPoint(convexSquare.getPoint(0));
    vOrigin = convexSquare.getPoint((angle1));
    pTree(L, N, vPoint, vOrigin, rotation);
    angle1 = ((angle1 + 1) % 4);

    // Generate right side
    vPointR = convexSquare.getTransform().transformPoint(convexSquare.getPoint(3));
    vOrigin = convexSquare.getPoint(2);
    pTree(L, N, vPointR, vOrigin, rotation-90);
    }
  }
}
*/
void PTree::drawPtree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent)
{
  static const float halfSqrt2 = sqrt(2.f) / 2;

  if(N < 1) return; // Ends the recursion
  target.draw(parent);
  auto const& sz = parent.getSize();
  auto const& tf = parent.getTransform();

  // Left side recursion call
  auto childL = parent;
  childL.setSize(sz * halfSqrt2);
  childL.setOrigin(0, childL.getSize().y);
  childL.setPosition(tf.transformPoint({0, 0}));
  childL.rotate(-45);
  PTree::drawPtree(target, N - 1, childL);

  // Right side recursion call
  auto childR = parent;
  childR.setSize(sz * halfSqrt2);
  childR.setOrigin(childR.getSize());
  childR.setPosition(tf.transformPoint({sz.x, 0}));
  childR.rotate(45);
  PTree::drawPtree(target, N - 1, childR);
}

void PTree::drawPtree(sf::RenderTarget& target, const float L, const int N)
{
  // Set origin to center of the rectangle
  sf::RectangleShape rect{{L, L}};

  rect.setOrigin(rect.getSize() / 2.f);
  rect.setPosition(target.getSize().x / 2.f, target.getSize().y - L / 2.f);
  rect.setFillColor(sf::Color::Blue); // EXTRA CREDIT: Add color
  PTree::drawPtree(target, N, rect);
}
