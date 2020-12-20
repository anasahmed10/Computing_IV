#include <iostream>
#include <string>
#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "fiblsfr.hpp"
using namespace std;

sf::Image transform(sf::Image image, FibLSFR *bitShift);

int main(int argc, char *argv[]){
  int x, y;
  FibLSFR colorCounter;
  sf::Image image1, image2;

  if(!image1.loadFromFile(argv[1]))
    return -1;
  if(!image2.loadFromFile(argv[1]))
    return -1;

  colorCounter.setSeed(argv[argc - 1]);

  image2 = transform(image2, &colorCounter);  // Transforms the image once they are loaded

  // Converts the images to sprites to prepare them for displaying

  sf::Texture texture1, texture2;
  texture1.loadFromImage(image1);
  texture2.loadFromImage(image2);

  sf::Sprite sprite1, sprite2;
  sprite1.setTexture(texture1);
  sprite2.setTexture(texture2);

  sf::RenderWindow window1(sf::VideoMode(800, 600), "Original"), window2(sf::VideoMode(800, 600), "Morphed");  // Opening the windows after the transform function is called helps a lot with optimization

  while(window1.isOpen() && window2.isOpen()){  // Runs draws both sprites in both windows
    sf::Event event;
    while(window1.pollEvent(event))
      {
	if(event.type == sf::Event::Closed)
	   window1.close();
      }
    while(window2.pollEvent(event))
      {
	if(event.type == sf::Event::Closed)
	   window2.close();
      }
    // Now loads the sprites
    window1.clear();
    window1.draw(sprite1);
    window1.display();

    window2.clear();
    window2.draw(sprite2);
    window2.display();
  }

  if(!image2.saveToFile(argv[2])) // Special case if the program is unable to save the encrypted image
    return -1;

  return 0;
}

sf::Image transform(sf::Image image, FibLSFR *bitShift){
      sf::Color p;
      unsigned int x, y;
      sf::Vector2u v1;
      v1 = image.getSize();     // Gets the size of the image and uses it for the bounds of the for loops


    for(x = 0; x < v1.x; x++){
        for(y = 0; y < v1.y; y++){
        p = image.getPixel(x, y);
        // The sum of the generate function will be applied for each color of pixel p
        p.r = p.r ^ bitShift->generate(8);
        p.g = p.g ^ bitShift->generate(8);
        p.b = p.b ^ bitShift->generate(8);
        image.setPixel(x, y, p);     // Sets the pixel
        }
    }
      return image;
}
