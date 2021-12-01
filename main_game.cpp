//Main
#include <iostream>
#include <vector>
#include <fstream> // for file input and output ('saved game')
#include "random_guessing_number.h"
using namespace std;

vector<int> processed(vector<int>& remaining_numbers_not_guessed, vector<int>& numbers_already_guessed) {
  // delete items in the vector 'numbers_already_guessed' from the vector 'remaining_numbers_not_guessed'
  int number_of_numbers_already_guessed = numbers_already_guessed.size();
  if (number_of_numbers_already_guessed == 0) {
    remaining_numbers_not_guessed = remaining_numbers_not_guessed;
  }
  
  if (number_of_numbers_already_guessed != 0) {
          int A=0;
          vector<int>::iterator B = remaining_numbers_not_guessed.begin();
          int item_to_be_deleted;
          while (A < numbers_already_guessed.size()) {
            item_to_be_deleted = numbers_already_guessed[A];
            while (B != remaining_numbers_not_guessed.end()) {
              if (*B == item_to_be_deleted) {
                B++;
                remaining_numbers_not_guessed.erase(B - 1);
                B--;
              }
              B++;
            }
            B = remaining_numbers_not_guessed.begin();
            A++;
          }
        }
  return remaining_numbers_not_guessed;
}

int main() {
  cout << "Welcome to this game! \nTry your luck and see if you are lucky or not today! \n\n"; //Welcoming
  
  vector<int>remaining_numbers_not_guessed;
  vector<int>numbers_already_guessed;
  vector<int>numbers_guessed_right;
  // vector of numbers guessed wrong: no need
    // instruction code
    char instruction_code;
    cout << "Enter 'L' to load the previous saved game" << endl << "Enter 'S' to start a new game" << endl;
    cout << "Enter 'Q' to quit the game" << endl;
    cin >> instruction_code;
    while (instruction_code != 'Q') {
      if (instruction_code != 'L' && instruction_code != 'S') {
        cout << "Invalid input. Please enter 'L', 'S' or 'Q' to continue. " << endl;
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
        int a=0;
        while (a<Number_of_terms_of_vector_v^2) {
          b = a + 1;
          remaining_numbers_not_guessed.push_back(b);
        }
        remaining_numbers_not_guessed = processed(remaining_numbers_not_guessed, numbers_already_guessed);
        Number_of_attempts_allowed = 7; //declare max number of attempt if input grid is 3
        
      }
      if (Number_of_terms_of_vector_v == 4) {
        int a=0;
        while (a<Number_of_terms_of_vector_v^2) {
          b = a + 1;
          remaining_numbers_not_guessed.push_back(b);
        }
        remaining_numbers_not_guessed = processed(remaining_numbers_not_guessed, numbers_already_guessed);
        Number_of_attempts_allowed = 12; //declare max number of attempt if input grid is 4
      }
      if (Number_of_terms_of_vector_v != 3 && Number_of_terms_of_vector_v != 4) {
        cout << "Sorry, please input either '3' or '4' only. Thank you. " << endl;
        cin >> Number_of_terms_of_vector_v;
      }
      run_game(remaining_numbers_not_guessed, Number_of_attempts_allowed); //run the 'guessing random number' game
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
