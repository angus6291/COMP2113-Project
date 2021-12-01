//Main
#include <iostream>
#include <vector>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include "guessing_random_number.h"
using namespace std;

vector<int>remaining_numbers_not_guessed;

vector<int>numbers_already_guessed;

vector<int>numbers_guessed_right;

int Number_of_attempts_allowed;

void run_guessing_random_number_game(vector<int> remaining_numbers_not_guessed, int Number_of_attempts_allowed, int Number_of_terms_of_vector_v) {
  int X=remaining_numbers_not_guessed.size();
  if (X == 0) {
    break;
  }
  srand(time(NULL)); // initialize the seed for rand()
  // the index must be smaller than remaining_numbers_not_guessed.size(), can start from 0
  int index_of_number_to_be_guessed_in_the_remaining_numbers_list = rand() % X;
  int number_to_be_guessed = remaining_numbers_not_guessed[index_of_number_to_be_guessed_in_the_remaining_numbers_list];
  bool is_guessed_correctly = false;
  int remaining_number_of_attempts_allowed = Number_of_attempts_allowed;
  int guess;
  while (remaining_number_of_attempts_allowed > 0) {
    if (Number_of_terms_of_vector_v == 3) {
      cout << "Please make a guess (1 - 9). ";
      if (remaining_number_of_attempts_allowed == Number_of_attempts_allowed) {
      cout << "You have " << remaining_number_of_attempts_allowed << " chances left. Wish you all the best. Good luck! \n";
    }
      else if (remaining_number_of_attempts_allowed > 5) {
        cout << "You have " << remaining_number_of_attempts_allowed << " chances left. \n";
    }
      else if (remaining_number_of_attempts_allowed > 3) {
        cout << "You still have " << remaining_number_of_attempts_allowed << " chances left. I hope you can guess the correct number within the chances left. \n";
      }
      else if (remaining_number_of_attempts_allowed > 1) {
        cout << "You have only " << remaining_number_of_attempts_allowed << " chances left. Please seize the only chances left. \n";
      }
      else {
        cout << "You have only 1 chance left. Seems like you are rather unlucky now. I hope you can create the miracle of guessing the correct number with such a faint chance. \n";
      }
    }
    
    if (Number_of_terms_of_vector_v == 4) {
      cout << "Please make a guess (1 - 16). ";
    if (remaining_number_of_attempts_allowed == Number_of_attempts_allowed) {
      cout << "You have " << remaining_number_of_attempts_allowed << " chances left. Wish you all the best. Good luck! \n";
    }
    else if (remaining_number_of_attempts_allowed > 7) {
        cout << "You have " << remaining_number_of_attempts_allowed << " chances left. \n";
    }
      else if (remaining_number_of_attempts_allowed > 3) {
        cout << "You still have " << remaining_number_of_attempts_allowed << " chances left. I hope you can guess the correct number within the chances left. \n";
      }
      else if (remaining_number_of_attempts_allowed > 1) {
        cout << "You have only " << remaining_number_of_attempts_allowed << " chances left. Please seize the only chances left. \n";
      }
      else {
        cout << "You have only 1 chance left. Seems like you are rather unlucky now. I hope you can create the miracle of guessing the correct number with such a faint chance. \n";
      }
    }
    
    cin >> guess;
    
    if (guess == number_to_be_guessed) {
      is_guessed_correctly = true;
      numbers_guessed_right.push_back(number_to_be_guessed);
      if (remaining_number_of_attempts_allowed == Number_of_attempts_allowed) {
        cout << "WOW! YOU'VE GUESSED THE CORRECT NUMBER WITHOUT NEEDING MORE ATTEMPTS! \nBRAVISSIMO!!! Seems like you are super lucky today!!! I hope your luck will last long!!" << endl;
        break;
      }
      else if (remaining_number_of_attempts_allowed >= Number_of_attmepts_allowed - 3) {
        cout << "Wow! You have guessed the correct number with only a few attempts! \nBravo! You are very lucky today!! I hope your luck will last long!!" << endl;
        break;
      }
      else if (remaining_number_of_attempts_allowed > 3) {
        cout << "You've guessed the correct number without needing too many chances. \nSeems like you are quite lucky today. I hope your luck will last long and wish you a luckier future." << endl;
        break;
      }
      else if (remaining_number_of_attempts_allowed > 1) {
        cout << "You've guessed the correct number finally. You are very near to the failure but fortunately you have successfully seized your chances. \nI wish you a luckier future." << endl;
        break;
      }
      if (remaining_number_of_attempts_allowed == 1) {
        cout << "WOW! Congratulations that you've really made the miracle! \nI believe that you will be much luckier in the future. " << endl;
        break;
      }
      break;
      }
    if (guess != number_to_be_guessed) {
    remaining_number_of_attempts_allowed--;
    }
  }
  if (is_guessed_correctly = false) {
    cout << "I am so sorry that you can't make the miracle. You still cannot guess the correct number. \nBut I believe that you will be luckier in the future." << endl;
  }
  remaining_numbers_not_guessed.erase(index_of_number_to_be_guessed_in_the_remaining_numbers_list);
  if (Number_of_terms_of_vector_v == 3) {
    Number_of_attempts_allowed = 7;
  }
  if (Number_of_terms_of_vector_v == 4) {
    Number_of_attempts_allowed = 10;
  }
}

int main() {
  cout << "Welcome to this game! \nTry your luck and see if you are lucky or not today! \n\n"; //Welcoming
  
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
      cout << "Input '3' to have a 3x3 bingo board or '4' to have a 4x4 bingo board" << endl;
      cin >> Number_of_terms_of_vector_v;
      while (Number_of_terms_of_vector_v != 3 && Number_of_terms_of_vector_v != 4) {
        cout << "Sorry, we don't provide smaller or larger grids than the 3x3 and 4x4 grids. \nPlease input either '3' or '4' only. Thank you. " << endl;
        cin >> Number_of_terms_of_vector_v;
      }
      if (Number_of_terms_of_vector_v == 3 || Number_of_terms_of_vector_v == 4) {
        int a=0;
        while (a < Number_of_terms_of_vector_v ** 2) {
          b = a + 1;
          remaining_numbers_not_guessed.push_back(b);
        }
        if (Number_of_terms_of_vector_v == 3) {
        Number_of_attempts_allowed = 7; //declare max number of attempt if input grid is 3
        }
        else {
          Number_of_attempts_allowed = 10;
        }
      }
      //run the 'guessing random number' game
      run_guessing_random_number_game(remaining_numbers_not_guessed, Number_of_attempts_allowed, Number_of_terms_of_vector_v); 
      
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
