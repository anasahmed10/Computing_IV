/*  Copyright Anas Ahmed  */

#include <string>
#include "model.hpp"

int main(int argc, const char* argv[]) {
  // Make sure that the program was called properly
  if (argc != 3) {
    std::cout << "Usage: ./TextGenerator (int K) (int T)\n";
    return 0;
  }

  // For some reason, has to be a string to please -fpermissive
  // error: cast from ‘const char*’ to ‘int’ loses precision [-fpermissive]
  std::string str_k(argv[1]);
  std::string str_t(argv[2]);

  // Converts the command line arguments as ints
  int k = std::stoi(str_k);
  int t = std::stoi(str_t);

  // Now takes input
  std::string input = "";
  std::string current_txt = "";   // Set inputs to NULL before, to be safe

  while (std::cin >> current_txt) {
    input += " " + current_txt;
    current_txt = "";
  }

  // Outputs the users input for troubleshooting
  std::cout << "ORIGINAL INPUT TEXT: \n\n";

  // Only show the first T characters
  for (int a = 0; a < t; a++) {
    std::cout << input[a];

    // Fomrats the text better
    if (input[a] == '.' || input[a] == '!') {
      std::cout << "\n";
    }
  }

  // First make a final output string to use.
  std::string output_string = "";

  // Initializes an mModel object using input as the string and k as the int
  mModel amazing(input, k);

  output_string += "" + amazing.gen(input.substr(0, k), t);

  // Creates space before the output for visibility
  std::cout << "\n\nFINAL OUTPUT TEXT: \n\n";

  // Formats output similar to the input
  for (int a = 0; a < t; a++) {
    std::cout << output_string[a];

    // More text formatting
    if (output_string[a] == '.' || output_string[a] == '!') {
      std::cout << "\n";
    }
  }
  std::cout << "\n";

  return 0;
}
