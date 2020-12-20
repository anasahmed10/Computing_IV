#include <iostream>
#include <string>
#include "fiblsfr.hpp"
using namespace std;

int main(int argc, char *argv[]){
  FibLSFR test1("0110110001101100"), test2("1100011011000011"), test3("1100100");
  int testresult;
  
  cout << "Original:  " << test1 << endl; // Shows the original bits before cshifting
  for(int i = 1; i < 10; i++){
    testresult = test1.step();
    cout << i << " steps:   " << test1 << " " << testresult << endl; // Shows the stepped bits then the last bit right after
  }
  for(int i = 0; i < 7; i++){
   test2.generate(5);
  }

  test3.generate(7);
  return 0;
}
