/*
⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠰⡿⠿⠛⠛⠻⠿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣄⡀⠀⠀⠀⠀⢀⣀⣀⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⣿⣿⣷⠀⠀⠀⠀⠛⠛⣿⣿⣿⡛⠿⠷⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠘⠿⠿⠋⠀⠀⠀⠀⠀⠀⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣿⣷⣄⠀⢶⣶⣷⣶⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠈⠙⠻⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣰⣿⣿⣿⠀⠀⠀⠀⢀⣀⣠⣤⣴⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣠⣾⣿⣿⣿⣥⣶⣶⣿⣿⣿⣿⣿⠿⠿⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠛⢿⣿⣿⣿⣿⣿⣿⡿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
this image was my face the entire time i was working on this assignment... */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include <vector>
#include <math.h>
#include <memory>

int Universe::addBody(CelestialBodies &newBody) // adds a celstial body to the vector
{

	unsigned int temp = myVectorPointer->size();

	myVectorPointer->push_back(std::make_unique<CelestialBodies>(newBody));// you cannot copy a unique vector so it
										// is declared in the push back function call

	if(temp >= myVectorPointer->size())// if the size has not changed return 1
		return 1;

	std::cout << "A Celestial Body was added to the universe" << std::endl; // confirms that the operation was completed successfully

	return 0;
}

std::istream& operator>>(std::istream &input, CelestialBodies &otherBody)
{

	input >> otherBody.x >> otherBody.y;
	input >> otherBody.vX >> otherBody.vY;
	input >> otherBody.mass >> otherBody.textureString >> otherBody.R;

	if(otherBody.image.loadFromFile(otherBody.textureString))
		return input;

	otherBody.texture.loadFromImage(otherBody.image);
	otherBody.sprite.setTexture(otherBody.texture);
	otherBody.sprite.setPosition((otherBody.x/otherBody.R)*250+250,(otherBody.y/otherBody.R)*250+250);
	return input;
}

void CelestialBodies::computeForces(float curr_mass, float Xposition, float Yposition/*, int debug*/){
	// mass, Xposition, and Yposition all corelate to the object that we are calculating the change in velocity for
	// step calulates the change in velocity of the body in respect to the current body passed into the function
	// this function finds the force acting on the body and calculates a new velocity accordingly
	// after this function is called for every object in the vector, the new velocity will be the sum of all the forces
	// acting on the body

	// Formulas: F = ( G * this_mass * other_mass ) / ( r ^ 2 )
	//	     r = sqrt( deltaX^2 + deltaY^2 )
	//	     F(x or y) = F * (delta / r)

	const double G = 6.67e-11;
	double delta_X = Xposition - x;
	double delta_Y = Yposition - y;
	double r_squared = pow(delta_X, 2) + pow(delta_Y, 2);
	double r = sqrt(r_squared);
	double F = (G * mass * curr_mass)/r_squared;
	force_X = force_X + (F * (delta_X/r));
	force_Y = force_Y + (F * (delta_Y/r));

	// now that we have the forces for x and y we can calculate the acceleration in the step function
	return;
}

void CelestialBodies::step(double seconds)
{
	// force / mass = acceleration
	vX = vX + ((force_X/mass) * seconds);
	vY = vY + ((force_Y/mass) * seconds);

	x = x + (vX * seconds);
	y = y + (vY * seconds);

	//std::cout << this->x << ", " << this->y << std::endl;

	sprite.setPosition((x/R)*250+250, (y/R)*250+250);

	return;
}
