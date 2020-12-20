#include "body.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <iterator>

int main(int argc,char *argv[]){

  int uParticles;
  double uRadius;

  sf::RenderWindow window1(sf::VideoMode(500, 500), "Space");
  sf::Image backgroundimage;
  backgroundimage.loadFromFile("starfield.jpg");

  sf::Texture background_texture;
  background_texture.loadFromImage(backgroundimage);

  sf::Sprite background_sprite;
  background_sprite.setTexture(background_texture);

  window1.setFramerateLimit(60);

  std::cout << std::scientific;

  // Uses smart pointers for universe
  std::unique_ptr<universe>u(new universe());
  cBody* planet;

  std::cin >> uParticles >> uRadius;
  window1.draw(background_sprite);
  window1.display();
  cout << "Input: " << uParticles << " uRadius: " << uRadius << endl;
  for(int i = 0; i < uParticles;i++)
    {
      planet = new cBody();
      cin >> *planet;
      (*u).pushback(*planet);
      cout << *planet;
    }
  (*u).draw(window1);
  window1.display();
  while (window1.isOpen())
    {
      sf::Event event;
      while(window1.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    {
	      window1.close();
	    }
	  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    {
	      window1.close();
	    }
	}
      window1.display();
    }
  return 0;
}
