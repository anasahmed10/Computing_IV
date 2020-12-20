#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::Texture texture;

    window.setVerticalSyncEnabled(true);  //Enable V-sync

    if(!texture.loadFromFile("sprite.jpg"))  //Load Sprite
      return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) // Load Font
      return EXIT_FAILURE;
    sf::Text text("The Falcons blew a 28-3 lead", font, 50);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
	// Search for inputs
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	  sprite.move(2, 0);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	  sprite.move(-2, 0);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	  sprite.move(0, -2);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	  sprite.move(0, 2);

	// Display sprite and font
	window.clear();
	window.draw(sprite);
	window.draw(text);
	window.display();
    }

    return 0;
}
