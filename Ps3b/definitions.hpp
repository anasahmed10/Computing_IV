#ifndef DEFS
#define DEFS
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class CelestialBodies:public sf::Drawable
{
public:

	CelestialBodies(float posX, float posY, float velX, float velY, float planet_mass, float radius, std::string texture_string)
	{
		x = posX;
		y = posY;

		std::cout << x << ", " << y << std::endl;

		vX = velX;
		vY = velY;
		mass = planet_mass;
		R = radius;
		textureString = texture_string;

		force_X = 0;
		force_Y = 0;

		if(!image.loadFromFile(textureString))
			return;

		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition((x/R)*250+250, (y/R)*250+250); //gives us the ratio of the x and y values then adds 250 to move to the center of the window
	};

	void step(double seconds);

	void setForcesZero(){force_X = 0, force_Y = 0;};

	float getXpos() const {return x;};
	float getYpos() const {return y;};
	float getXvelocity() const {return vX;};
	float getYvelocity() const {return vY;};
	float getMass() const {return mass;};
	std::string getTextureString() const {return textureString;};

	void computeForces(float curr_mass, float Xposition, float Yposition/*, int debug*/);

	friend std::istream& operator>>(std::istream &input, CelestialBodies &otherBody);

	~CelestialBodies(){};

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(sprite);
	}

	float x;
	float y;
	float vX;
	float vY;
	float mass;
	float R;
	std::string textureString;

	double force_X;
	double force_Y;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

};

class Universe
{
public:
	Universe(){myVectorPointer = new std::vector<std::unique_ptr<CelestialBodies>>;};

	int addBody(CelestialBodies &newBody);

	std::vector<std::unique_ptr<CelestialBodies>>::iterator begin(){return myVectorPointer->begin();};
	std::vector<std::unique_ptr<CelestialBodies>>::iterator end(){return myVectorPointer->end();};

	//&std::vector<std::unique_ptr<CelestialBodies>> getVectorPointer(){retun myVectorPointer;};

	~Universe()
	{
		auto it = myVectorPointer->begin();
		for(;it != myVectorPointer->end(); it++){
			it->reset();
		}
		delete myVectorPointer;
	};

private:
	std::vector<std::unique_ptr<CelestialBodies>> *myVectorPointer;
};

#endif
