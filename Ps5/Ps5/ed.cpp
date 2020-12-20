#include "ed.hpp"

ed::ed() {}

ed::ed(string firstString, string secondString) {
  stringOne = firstString;
  stringTwo = secondString;
}

ed::~ed() {}

int ed::penalty(char a, char b) {
  if(a == b) {return 0;}

  else if(a != b) {return 1;}

  return -1;
}

int ed::min(int a, int b, int c) {
  if(a < b && a < c) {return a;}
  else if(b < a && b < c) {return b;}
  else if(c < a && c < b) {return c;}

  return a;
}

int ed::optDistance() {
  int oneL, twoL, i, j;

  oneL = stringOne.length();
  twoL = stringTwo.length();

  for(i = 0; i <= twoL; i++) {
    std::vector<int> tmp;
    matrix.push_back(tmp);

    for(j = 0; j <= oneL; j++) {
      matrix.at(i).push_back(0);
    }
  }

  // Begin filling out the matrix, starting with bottom row
  for(i = 0; i <= oneL; i++) {
    matrix[i][twoL] = 2 * (twoL - i);
  }

  // Now will fill out the side row
  for(j = 0; j <= twoL; j++) {
    matrix[oneL][j] = 2 * (oneL - j);
  }

  // Calculates the rest of the matrix using Princeton's Formula
  for(i = oneL - 1; i >= 0; i--) {
    for(j = twoL - 1; j >= 0; j--) {
      int opt1 = matrix[i+1][j+1] + penalty(stringOne[j], stringTwo[i]);
      int opt2 = matrix[i+1][j] + 2;
      int opt3 = matrix[i][j+1] + 2;

      matrix[i][j] = min(opt1, opt2, opt3);
    }
  } 
  return matrix[0][0];
}

string ed::align() {
  std::ostringstream returnString;

  int oneL = stringOne.length();
  int twoL = stringTwo.length();

  int i = 0, j = 0;
  int penal, opt1, opt2, opt3;
  string retString;

  while(i < twoL || j < oneL) {
    // Uses try blocks to check vector bounds
    try {
      penal = penalty(stringOne[j], stringTwo[i]);
      opt1 = matrix.at(i+1).at(j+1) + penal;
    }
    catch(const std::out_of_range& error) {
      opt1 = -1;
    }

    try {
      opt2 = matrix.at(i).at(j) + 2;
    }
    catch(const std::out_of_range& error) {
      opt2 = -1;
    }

    try {
      opt3 = matrix.at(i).at(j+1) + 2;
    }
    catch(const std::out_of_range& error) {
      opt3 = -1;
    }

    if(matrix[i][j] == opt1) {
      returnString << stringOne[j] << " " << stringTwo[i] << " " << penal << "\n";
      i++;
      j++;
    }

    else if(matrix[i][j] == opt2) {
      returnString << "- " << stringTwo[i] << " 2\n";
      i++;
    }

    else if(matrix[i][j] == opt2) {
      returnString << " -" << stringOne[j] << " 2\n";
      j++;
    }
  }

  retString = returnString.str();
  return retString;
}
