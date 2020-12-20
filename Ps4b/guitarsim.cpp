#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "ringbuffer.hpp"
#include "stringsound.hpp"
using std::cout;
using std::endl;
#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

std::vector<int16_t> makeSamples(StringSound gs) {
  std::vector<int16_t> samples;
  cout << "pluck this" << endl;
  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {

  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
  cout << "Window Created" << endl;
  sf::Event event;
  double freq;
  std::vector<int16_t> samples;
  freq = CONCERT_A;
  cout << "Sampels" << endl;
  StringSound gs1(freq);
  sf::Sound sound1;
  sf::SoundBuffer buf1;

  cout << "sound1 created" << endl;
  
  samples = makeSamples(gs1);
  sound1.setBuffer(buf1);

  freq = CONCERT_A * pow(2, 3.0/12.0);

  StringSound gs2(freq);
  sf::Sound sound2;
  sf::SoundBuffer buf2;

  cout << "sound2 created" << endl;
  
  samples = makeSamples(gs2);
  sound2.setBuffer(buf2);

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::A:
          sound1.play();
          break;

        case sf::Keyboard::C:
          sound2.play();
          break;

        default:
          break;
        }
	
      default:
        break;
      }
      window.clear();
      window.display();
    }
  }
  return 0;
}
