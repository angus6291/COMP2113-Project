//Main
#include <iostream>
#include <vector>
#include <fstream>
#include "run_game.h"
using namespace std;

int main() {
  cout << "Welcome to this game! Try your luck and see if you are lucky or not today!!!" <<endl; //Welcoming
  
    // instruction code
    char instruction_code;
    cout << "Enter 'L' to load the previous saved game" << endl << "Enter 'S' to start a new game" << endl;
    cout << "or enter 'Q' to quit the game" << endl;
    cin >> instruction_code;
    while (instruction_code != 'Q') {
      if (instruction_code != 'L' && instruction_code != 'S') {
        cout << "Invalid input" << endl << "Please enter 'L', 'S' or 'Q' to continue" << endl;
        cin >> instruction_code;
      }
    if (instruction_code == 'L') {
      //to be implemented load from save
    }
    if (instruction_code == 'S') {
      //run new game
      int Number_of_terms_of_vector_v; //Decide either 3*3 or 4*4 grid
      int Number_of_attempts_allowed; //universal number of attempt allowed
      cout << "Input '3' to have a 3x3 bingo board or '4' to have a 4x4 bingo board" << endl;
      cin >> Number_of_terms_of_vector_v;
      if (Number_of_terms_of_vector_v == 3) {
        Number_of_attempts_allowed = 7; //declare max number of attempt if input grid is 3
      }
      if (Number_of_terms_of_vector_v == 4) {
        Number_of_attempts_allowed = 12; //declare max number of attempt if input grid is 3
      }
      if (Number_of_terms_of_vector_v != 3 && Number_of_terms_of_vector_v != 4) {
        cout << "Sorry, please input either '3' or '4' only. Thank you. " << endl;
        cin >> Number_of_terms_of_vector_v;
      }
      run_game(Number_of_terms_of_vector_v, Number_of_attempts_allowed); //run the 'guessing random number' game
      //load bingo board
      
    }
    }
    if (instruction_code == 'Q') {
      //Leave game
      cout << "Thank you! \nSee you next time!!";
      exit(1);
    }

    cout << "This is the end of the game, see u!!" << endl;
    return 0;
}
