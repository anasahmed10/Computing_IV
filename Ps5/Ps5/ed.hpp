#ifndef ED_HPP
#define ED_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <SFML/System.hpp>
using std::string;

class ed {
 public:
  ed();
  ed(string firstString, string secondString);
  ~ed();
  int penalty(char a, char b);
  int min(int a, int b, int c);
  int optDistance();
  string align();
 private:
  string stringOne, stringTwo;
  std::vector<std::vector<int>> matrix;
};

#endif
