//for output and testing whether there's bingo
//first of all seperate into either 3*3 or 4*4
//vector will be set for dynamic storage
#include <iostream>
#include <string>
#include <vector>
#include " "
using namespace std;

void output(int Number_of_terms_of_vector_v) {
  // if 3*3 grid, create {1,2,3,...,7,8,9}
  if (Number_of_terms_of_vector_v == 3) {
    //declare output vector for storing outputs when grid = 3*3
    vector<str>output;
    for (int i=0; i<3^2, i++) {
      string s = to_string (i+1);
      output[i] = s;
    }
  }
  // if 4*4 grid, create {1,2,3,...,14,15,16}
  else if (Number_of_terms_of_vector_v == 4) {
    //declare output vector for storing outputs when grid = 4*4
    vector<str>output;
    for (int i=0; i<4^2, i++) {
      string s = to_string (i+1);
      output[i] = s;
    }
  }
