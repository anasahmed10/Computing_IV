#ifndef BODY_HPP
#define BODY_HPP
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const sf::Vector2f window(500,500);
const double radius = 2.50e11;
using namespace std;

class cBody: public sf::Drawable
{
public:
  cBody();
  cBody(double x_position, double y_position, double x_velocity, double y_velocity, double bmass, std::string planet);
  friend ostream& operator <<(std::ostream &output, cBody& c);
  friend istream& operator >>(std::istream &input, cBody& d)
 {
    input >> d.xpos >> d.ypos >> d.xvel >> d.yvel >> d.mass >> d.picture;

  if(!d.pImage.loadFromFile(d.picture)){
    throw "Picture did not load";
  }
  d.pTexture.loadFromImage(d.pImage);
  d.pSprite.setTexture(d.pTexture);


  d.xpos = ((window.x/radius) * d.xpos/2) + (window.x / 2);
  d.ypos = ((window.y/radius) * d.ypos/2) + (window.y / 2);

  d.pSprite.setPosition(sf::Vector2f(d.xpos, d.ypos));
  return input;
 }
  void draw(sf::RenderTarget& obj, sf::RenderStates status) const;
private:
  double xpos;
  double ypos;
  double xvel;
  double yvel;
  double mass;
  std::string picture;

  sf::Image pImage;
  sf::Sprite pSprite;
  sf::Texture pTexture;
};

class universe{
public:
	void draw(sf::RenderWindow& window1){
	for(unsigned int i = 0; i < uni.size();i++){
	    window1.draw(uni[i]);
		cout << "Called Loop " << i <<endl;
    }
    }
	void pushback(cBody obj)
    {
	uni.push_back(obj);
	}

private:
 	std::vector<cBody> uni;
};


#endif
