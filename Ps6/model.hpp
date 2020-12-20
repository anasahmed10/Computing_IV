/*  Copyright Anas Ahmed  */

#ifndef MODEL_HPP
#define MODEL_HPP
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>


class mModel {
 public:
  /* Creates a Markov model of order k from the given text.
   * Assume that the text has a length of at least k.               */
  mModel(std::string text, int k);

  // Order k of Markov model
  int order();

  /* Returns number of occurrences of kgram in text.
   * Throws an exception if kgram is not of length k              */
  int freq(std::string kgram);

  /* Number of times that character c follows kgram
   * If order = 0, return number of times char c appears
   * -> throw an exception if kgram is not of length k              */
  int freq(std::string kgram, char c);

  /* Random character following given kgram
   * -> Throw an exception if kgram is not of length k.
   * -> Throw an exception if no such kgram.                        */
  char randk(std::string kgram);

  /* Generate a string of length T characters by simulating a
   * trajectory through the corresponding Markov chain.             */
  std::string gen(std::string kgram, int T);

  /* overload the stream insertion operator and display the internal
   * state of the Markov Model. Print out the order, the alphabet,
   * and the frequencies of the k-grams and k+1-grams.              */
  friend std::ostream& operator<< (std::ostream &out, mModel &mm);

 private:
  int _order;
  std::map <std::string, int> kgrams;
  std::string alphabet;
};
#endif
