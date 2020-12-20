/*  Copyright Anas Ahmed  */

#include "model.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

/* Creates a Markov model of order k from the given text.
 * Assumes that the text has a length of at least k.               */
mModel::mModel(std::string text, int k) {
  // Set the order.
  _order = k;

  // Seed the random number generator 
  srand((int)time(NULL)); //NOLINT

  std::string text_circular = text;   // Make a copy.

  for (int a = 0; a < _order; a++) {
    text_circular.push_back(text[a]);
  }

  int text_len = text.length();  // Find the text's length

  // Now we need to set the alphabet.
  char tmp;
  bool inAlpha = false;

  // Go through the entire text and pick out all the individual letters
  for (int i = 0; i < text_len; i++) {
    tmp = text.at(i);
    inAlpha = false;

    // Check if this letter has been added to the alphabet
    for (unsigned int y = 0; y < alphabet.length(); y++) {
      // tmp is already in the alphabet!
      // Also ignore upper case,
      if (alphabet.at(y) == tmp) {
        inAlpha = true;   // Match it as being in the alphabet.
      }
    }

    // If tmp isn't in the alphabet, isAlpha should be false
    if (!inAlpha) {
      alphabet.push_back(tmp);
    }
  }

  // Sorts alphabet, alphabetically
  std::sort(alphabet.begin(), alphabet.end());

  std::string tmp_str;
  int x, y;

  // Do up to text.length() substring comparisons.
  // This first part just "finds" kgrams and puts a "0" next to them.
  for (x = _order; x <= _order + 1; x++) {
    // Go through the entire text.
    for (y = 0; y < text_len; y++) {
      // This collects all given kgrams, and adds a "0" that we can use
      // later on to increment. We basically find ALL the kgrams, then
      // find their occurrences after.

      // current kgram we want.
      tmp_str.clear();
      tmp_str = text_circular.substr(y, x);

      // Insert the 0.
      kgrams.insert(std::pair<std::string, int>(tmp_str, 0));
    }
  }

  // Need an iterator for going through the kgrams map.
  std::map<std::string, int>::iterator it;
  int count_tmp = 0;

  // Uses same loop to count the kgrams
  for (x = _order; x <= _order + 1; x++) {
    for (y = 0; y < text_len; y++) {
      // Let's get the current kgram we're comparing against.

      tmp_str.clear();
      tmp_str = text_circular.substr(y, x);

      // Gets kgrams current count
      it = kgrams.find(tmp_str);
      count_tmp = it->second;

      // Increment the count by 1.
      count_tmp++;
      kgrams[tmp_str] = count_tmp;
    }
  }
}


// Returns _order
int mModel::order() {
  return _order;
}


/* Number of occurrences of kgram in text.					 */
int mModel::freq(std::string kgram) {
  // Throws an exception if kgram does not have length k
  if (kgram.length() != (unsigned)_order) {
    throw
      std::runtime_error("Error - kgram not of length k.");
  }

  // Uses std::map::find to search for the kgram
  std::map<std::string, int>::iterator it;
  it = kgrams.find(kgram);

  // Returns 0 if unable to find
  if (it == kgrams.end()) {
    return 0;
  }

  return it->second;
}


/* Number of times that character c follows kgram			  */
int mModel::freq(std::string kgram, char c) {
  // Throws an exception if kgram does not have length k
  if (kgram.length() != (unsigned)_order) {
    throw
      std::runtime_error("Error - kgram not of length k.");
  }

  // use std::map::find to see if we can find the kgram + c.
  std::map<std::string, int>::iterator it;
  kgram.push_back(c);
  it = kgrams.find(kgram);

  // If it equals map::end, we didn't find it, so return 0.
  if (it == kgrams.end()) {
    return 0;
  }

  return it->second;
}


/* Returns a random character following the given kgram			*/
char mModel::randk(std::string kgram) {
  // Throws an exception if kgram does not have length k
  if (kgram.length() != (unsigned)_order) {
    throw std::runtime_error("Error - kgram not of length k (randk)");
  }

  // Create an iterator for the map
  std::map<std::string, int>::iterator it;

  // Search through and see if we find the given kgram.
  it = kgrams.find(kgram);

  // Throws an exception if kgram is not found
  if (it == kgrams.end()) {
    throw std::runtime_error("Error - Could not find the given kgram! (randk)");
  }

  // Get the freq of the given kgram.
  int kgram_freq = freq(kgram);

  // This should be an int from 1 to the total number of possible letters.
  int random_value = rand() % kgram_freq; //NOLINT

  double test_freq = 0;
  double random_num = static_cast<double>(random_value) / kgram_freq;
  double last_values = 0;

  // Go through all the letters.
  for (unsigned int a = 0; a < alphabet.length(); a++) {
    // Calculates the probability as a double
    test_freq =  static_cast<double>(freq(kgram, alphabet[a])) / kgram_freq;


    if (random_num < test_freq + last_values && test_freq != 0) {
      // Returns matching letter
      return alphabet[a];
    }

    last_values += test_freq;
  }

  // Used for error checking only
  return '-';
}



std::string mModel::gen(std::string kgram, int T) {
  // Throw an exception if kgram is not of length k.
  if (kgram.length() != (unsigned)_order) {
    throw std::runtime_error("Error - kgram not of length k. (gen)");
  }

  // The final string we will return. We'll build it up over time.
  std::string final_string = "";

  // Temp char 
  char return_char;

  // Add the kgram to it.
  final_string += "" + kgram;


  for (unsigned int a = 0; a < (T - (unsigned)_order); a++) {
    return_char = randk(final_string.substr(a, _order));

    final_string.push_back(return_char);
  }

  return final_string;
}

std::ostream& operator<< (std::ostream &out, mModel &mm) {
  out << "\n_Order: " << mm._order << "\n";
  out << "Alphabet: "<< mm.alphabet << "\n";

  out << "Kgrams map: \n\n";

  std::map<std::string, int>::iterator it;

  for (it = mm.kgrams.begin(); it != mm.kgrams.end(); it++) {
    out << it->first << "\t" << it->second << "\n";
  }

  return out;
}
