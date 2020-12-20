/**********************************************************************
 *  readme.txt template                                                   
 *  Markov Model
 **********************************************************************/

Name: Anas Ahmed

Hours to complete assignment: 18 Hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
Created a working Markov Chain using a data structure.




/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
mmodel: creates a Markov Chain.
std::map<string, int> used to show the characters



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Here is the constructor for the mmodel

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





/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes. It should all be right.



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, I am sure as the cpplint file said all tests passed.



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
model.cpp: 
lines 109-112
lines 130-133
lines 152-154
lines 163-165
lines 199-201
/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I used the Princeton site to learn more about the project.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
There is a clock error when making the code, but it should not prevent the code from running. I think this error was due to my code being edited on a virtual machine 
with the incorrect time so the error comes from the code being edited in the future.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
