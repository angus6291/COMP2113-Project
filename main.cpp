//Main
#include <iostream>
#include <vector>
#include " "
using namespace std;

int main() {
  int Number_of_terms_of_vector_v; //Decide either 3*3 or 4*4 grid
  int Number_of_attempts_allowed; //universal number of attempt allowed
  cin << Number_of_terms_of_vector_v;
  if (Number_of_terms_of_vector_v == 3) {
    Number_of_attempts_allowed = 7;
  }
  else if (Number_of_terms_of_vector_v == 4) {
    Number_of_attempts_allowed = 12;
  }

}
