//Main
#include <iostream>
#include <vector>
#include <fstream>
#include "run_game.h"
using namespace std;

int main() {
  cout << "Welcome to the 'Guess the number game'!!!" <<endl; //Welcoming

  while (True) {
    // instruction code
    char instruction_code;
    cout << "Please enter the instruction code: 'L', Previous saved game will be loaded; ";
    cout << "'N', New game will be loaded; 'Y' Leave game";
    cin >> instruction_code;
    if (instruction_code == 'L') {
      //to be implemented load from save
    }
    else if (instruction_code == 'N') {
      //run new game
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
      run_game(Number_of_terms_of_vector_v, Number_of_attempts_allowed) //run the core game
      break
    }
    else if (instruction_code == 'Y') {
      //Leave game
      cout << "Thank you, see you next time!!"
    }
    else if (instruction_code != 'L' || instruction_code != 'N' || instruction_code != 'Y') {
      //re-enter code
      cout << "Invaid input Please re-enter instruction code"
    }

    cout << "This is the end of the game, see u!!" << endl;
    return 0;
}
