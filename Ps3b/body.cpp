#include "body.hpp"

cBody::cBody(){
  return;
}

cBody::cBody(double x_position, double y_position, double x_velocity, double y_velocity, double bmass, std::string planet)
{
  xpos = x_position;
  ypos = y_position;
  xvel = x_velocity;
  yvel = y_velocity;
  mass = bmass;
  picture = planet;



  if(!pImage.loadFromFile(picture)){
    return;
  }
  pTexture.loadFromImage(pImage);
  pSprite.setTexture(pTexture);

  std::cout << xpos << std::endl << ypos << std::endl;
}

std::ostream& operator <<(std::ostream &output, cBody& c){
  output << "current x Position: " << c.xpos << std::endl;
  output << "current y Postion: " << c.ypos << std::endl;
  output << "current x Velocity: " << c.xvel << std::endl;
  output << "current y Velocity: " << c.yvel << std::endl;
  output << "Particle Mass: " << c.mass << std::endl;
  output << "Particle Name: " << c.picture << std::endl;
  return output;
}
void cBody::draw(sf::RenderTarget& obj, sf::RenderStates status) const
{
  obj.draw(pSprite);
}

void cBody::setXPos(double newPosition){xpos = newPosition;}

void cBody::setYPos(double newPosition){ypos = newPosition;}

void cBody::setXVel(double newVelocity){xvel = newVelocity;}

void cBody::setYVel(double newVelocity){yvel = newVelocity;}

void cBody::setPositions(double radius, sf::Vector2u windowSize){
  double xW, yW;
  xW = windowSize.x;
  yW = windowSize.y;
  xpos = ((xW/radius) * xpos/2) + (xW/ 2);
  ypos = ((yW/radius) * ypos/2) + (yW / 2);
  pImage.loadFromFile(picture);
  pTexture.loadFromImage(pImage);
  pSprite.setTexture(pTexture);
  
  pSprite.setPosition(sf::Vector2f(xpos,ypos));  
  }

void cBody::findForces(double reg_mass, double xSpot, double ySpot){
  const double G = 6.67e-11;
  double deltaX = xSpot - xpos;
  double deltaY = ySpot - ypos;
  double r_square = pow(deltaX, 2) + pow(deltaY, 2);
  double r = sqrt(r_square);
  double F = (G * mass * reg_mass) / r_square;

  xforce = xforce + (F * (deltaX/r));
  yforce = yforce + (F * (deltaY/r));
}

void cBody::step(double seconds){
  double xacc, yacc;
  xacc = (xforce / mass) * seconds;
  yacc = (yforce / mass) * seconds;

  xvel += xacc;
  yvel += yacc;

  xpos += (xvel * seconds);
  ypos += (yvel * seconds);
}

double cBody::getXPos(){return xpos;}

double cBody::getYPos(){return ypos;}

double cBody::getXVel(){return xvel;}

double cBody::getYVel(){return yvel;}

double cBody::getMass(){return mass;}
