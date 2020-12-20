#include <iostream>
#include <string>
using namespace std;

class FibLSFR{
public:
  FibLSFR(string seed);

  FibLSFR();

  int setSeed(string newSeed);

  int step();

  int generate(int k);

  int bitstoint();

  friend ostream &operator <<(ostream& output, const FibLSFR see);

private:
  string LSFRseed;
};

FibLSFR::FibLSFR(string seed){
  LSFRseed = seed;
}

FibLSFR::FibLSFR(){
}

int FibLSFR::setSeed(string newSeed){
  LSFRseed = newSeed;
  return 0;
}

int FibLSFR::step(){
  char thirteen, twelve, ten, last;
  string newSeed = LSFRseed;

  thirteen = LSFRseed.at(2);
  twelve = LSFRseed.at(3);
  ten = LSFRseed.at(5);
  last = LSFRseed.front(); // Temporarily assigns last to the front bit before the XOR process begins

  // Checks fibonacci tap locations, if and else statements act as XOR function
  if(last == thirteen){last = '0';}
  else{last = '1';}
  if(last == twelve){last = '0';}
  else{last = '1';}
  if(last == ten){last = '0';}
  else{last = '1';}
  // last = char(front ^ thirteen ^ twelve ^ ten);

  // newSeed.at(0) = last;
  for(int i = 0; i < (LSFRseed.size() - 1); i++){
    // Special case, if at the end of the loop, back character is set
    if(i == (LSFRseed.size() - 2))
      newSeed.back() = last;
    newSeed.at(i) = LSFRseed.at(i + 1);
  }

  LSFRseed = newSeed;
  return int(last - 48); // last = 48 || 49, so must subtract it by 48 to get the return bit to 1 or 0
}

int FibLSFR::generate(int k){
  int i, re;

  // Runs the step function k amount of times
  for(i = 0; i < k; i++){
    this->step();
  }
  re = this->bitstoint();
  cout << LSFRseed << " " << re << endl;
  return re;
}

int FibLSFR::bitstoint(){
  int sum = 0, twoExponent = 1;

  // Loop adds the 2s power of each bit to the sum while increasing the exponent every time the loop increments
  for(int i = 0; i < 8; i++){
    sum += ((LSFRseed.at(LSFRseed.size() - 1 - i)) - 48) * twoExponent;
    twoExponent *= 2;
  }

  return sum;
}
ostream &operator <<(ostream &output, const FibLSFR see){
  output << see.LSFRseed;
  return output;
}

