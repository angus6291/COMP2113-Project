//for running the game and output status per every guess
//first of all seperate into either 3*3 or 4*4
//vector will be set for dynamic storage
#include <iostream>
#include <string>
#include <vector>
#include "guessing_random_number.h"
using namespace std;

void print_bingo_board(vector<string>bingo_board, int Number_of_terms_of_vector_v, vector<int>remaining_numbers_not_guessed, vector<int> numbers_guessed_right, vector<int> numbers_guessed_wrong) {
  int number_to_be_replaced;
  if (remaining_numbers_not_guessed.size() < Number_of_terms_of_vector_v ** 2) {
    if (numbers_guessed_right.size() != 0) {
      int I=0;
      while (I < numbers_guessed_right.size()) {
        number_to_be_replaced = numbers_guessed_right[I];
        if (bingo_board[number_to_be_replaced - 1] != "    O") {
            bingo_board[number_to_be_replaced - 1] = "    O";
        }
        I++;
      }
    }
    
    if (numbers_guessed_wrong.size() != 0) {
      int J=0;
      while (J < numbers_guessed_right.size()) {
        number_to_be_replaced = numbers_guessed_wrong[J];
        if (bingo_board[number_to_be_replaced - 1] != "    X") {
            bingo_board[number_to_be_replaced - 1] = "    X";
        }
        J++;
      }
    }
  }
  int i=0;
  while (i < bingo_board.size()) {
    if ((i + 1) % Number_of_terms_of_vector_v == 0) {
      cout << bingo_board[i] << endl;
    }
    else {
      cout << bingo_board[i];
    }
    i++;
  }
  
  
}

void run_guessing_random_number_game(vector<int> remaining_numbers_not_guessed, int Number_of_attempts_allowed, int Number_of_terms_of_vector_v) {
  int X=remaining_numbers_not_guessed.size();
  if (X <= 2) {
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
      cout << "Please make a guess (1 - 9). Press any number smaller than 1 or greater than 9 to save the progress of the bingo board before playing this round of 'guessing random number' game.\n";
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
    
    if (guess < 1 || guess > Number_of_terms_of_vector_v ** 2) {
      cout << "The 'guessing random number' game session is interrupted. The required progress is saved.";
      if (Number_of_terms_of_vector_v == 3) {
      remaining_number_of_attempts_allowed = 7; // reset the remaining number of attempts allowed to be 7 for 3x3 grid
      }
      else {
        remaining_number_of_attempts_allowed = 10; // reset the remaining number of attempts allowed to be 10 for 4x4 grid
      }
      // pass the bingo board, int remaining_number_of_attempts_allowed, vector remaining_numbers_not_guessed, vector numbers_guessed_right, vector numbers_guessed_wrong to Savefile.txt
      break;
    }
    }
    
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
    if (guess != number_to_be_guessed && guess >= 1 && guess <= Number_of_terms_of_vector_v ** 2) {
    remaining_number_of_attempts_allowed--;
    }
  }
  if (is_guessed_correctly = false) {
    numbers_guessed_wrong.push_back(number_to_be_guessed);
    cout << "I am so sorry that you can't make the miracle. You still cannot guess the correct number. \nBut I believe that you will be luckier in the future." << endl;
  }
  remaining_numbers_not_guessed.erase(index_of_number_to_be_guessed_in_the_remaining_numbers_list);
  if (Number_of_terms_of_vector_v == 3) {
    Number_of_attempts_allowed = 7;
  }
  if (Number_of_terms_of_vector_v == 4) {
    Number_of_attempts_allowed = 10;
  }
return print_bingo_board(bingo_board, Number_of_terms_of_vector_v, remaining_numbers_not_guessed, numbers_guessed_right, numbers_guessed_wrong);
}
