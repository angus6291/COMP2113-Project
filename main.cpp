//Main
#include <iostream>
#include <vector>
#include <fstream>
#include " "
using namespace std;

int main() {
  int Number_of_terms_of_vector_v; //Decide either 3*3 or 4*4 grid
  int Number_of_attempts_allowed; //universal number of attempt allowed
  cout << "Please Input the number of grid you want to play (3/4): " >> endl;
  cin >> Number_of_terms_of_vector_v;
  if (Number_of_terms_of_vector_v == 3) {
    Number_of_attempts_allowed = 7; //declare max number of attempt if input grid is 3
  }
  else if (Number_of_terms_of_vector_v == 4) {
    Number_of_attempts_allowed = 12; //declare max number of attempt if input grid is 3
  }

}
