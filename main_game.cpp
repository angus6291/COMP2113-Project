//Main
#include <iostream>
#include <vector>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include <algorithm> // for the 'count' function
#include "guessing_random_number.h"
using namespace std;

bool check_bingo(vector<int> numbers_guessed_right) { // called only if numbers_already_guessed.size() > 3
	if (numbers_guessed_right.size() < 3) {
		return false;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 1) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 2) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 3)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 4) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 5) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 6)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 7) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 8) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 9)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 1) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 9) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 5)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 1) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 4) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 7)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 2) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 5) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 8)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 3) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 5) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 7)) {
		return true;
	}
	if (count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 3) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 6) && count(numbers_guessed_right.begin(), numbers_guessed_right.end(), 9)) {
		return true;
	}
	else {
		return false;
	}
}

void save(vector<int> remaining_numbers_not_guessed, vector<int> numbers_guessed_right, vector<int> numbers_guessed_wrong, int Number_of_terms_of_vector_v, int Number_of_attempts_allowed) {
	//output to "Savefile.txt"
	ofstream fout("Savefile.txt");
	fout << "remaining_numbers_not_guessed ";
	for (int x=0; x < remaining_numbers_not_guessed.size(); x++) {
		if (x < remaining_numbers_not_guessed.size() - 1) {
			fout << remaining_numbers_not_guessed[x] << " ";
		}
		if (x == remaining_numbers_not_guessed.size() - 1) {
			fout << remaining_numbers_not_guessed[x] << " " << 0 << endl;
		}
	}
	
	fout << "numbers_guessed_right ";
	for (int y=0; y < numbers_guessed_right.size(); y++) {
		if (y < numbers_guessed_right.size() - 1) {
			fout << numbers_guessed_right[y] << " ";
		}
		if (y == numbers_guessed_right.size() - 1) {
			fout << numbers_guessed_right[y] << " " << 0 << endl;
		}
	}
	fout << "numbers_guessed_wrong ";
	for (int z=0; z < numbers_guessed_wrong.size(); z++) {
		if (z < numbers_guessed_right.size() - 1) {
			fout << numbers_guessed_right[y] << " ";
		}
		if (y == numbers_guessed_right.size() - 1) {
			fout << numbers_guessed_right[y] << " " << 0 << endl;
		}
	}
	fout << "#" << endl << Number_of_terms_of_vector_v << " " << Number_of_attempts_allowed;
	fout.close();
	remaining_numbers_not_guessed.clear();
	numbers_guessed_right.clear();
	numbers_guessed_wrong.clear();
	Number_of_terms_of_vector_v = 0;
	Number_of_attempts_allowed = 0;
}

void load(vector<int> remaining_numbers_not_guessed, vector<int> numbers_guessed_right, vector<int> numbers_guessed_wrong, int Number_of_terms_of_vector_v, int Number_of_attempts_allowed) {
	ifstream fin("Savefile.txt");
	string vector_list_to_be_loaded;
	int item_to_be_loaded_into_the_list;
	fin >> vector_list_to_be_loaded;
	while (vector_list_to_be_loaded != "#") {
		if (vector_list_to_be_loaded == "remaining_numbers_not_guessed") {
			fin >> item_to_be_loaded_into_the_list;
			while (item_to_be_loaded_into_the_list != 0) {
				remaining_numbers_not_guessed.push_back(item_to_be_loaded_into_the_list);
				fin >> item_to_be_loaded_into_the_list;
			}
		}
		
		if (vector_list_to_be_loaded == "numbers_guessed_right") {
			fin >> item_to_be_loaded_into_the_list;
			while (item_to_be_loaded_into_the_list != 0) {
				numbers_guessed_right.push_back(item_to_be_loaded_into_the_list);
				fin >> item_to_be_loaded_into_the_list;
			}
		}
		
		if (vector_list_to_be_loaded == "numbers_guessed_wrong") {
			fin >> item_to_be_loaded_into_the_list;
			while (item_to_be_loaded_into_the_list != 0) {
				numbers_guessed_wrong.push_back(item_to_be_loaded_into_the_list);
				fin >> item_to_be_loaded_into_the_list;
			}
		}
		
		fin >> vector_list_to_be_loaded;
	}
	fin >> Number_of_terms_of_vector_v >> Number_of_attempts_allowed;
	fin.close();
}

void print_bingo_board(vector<string>bingo_board, int Number_of_terms_of_vector_v, vector<int>remaining_numbers_not_guessed, vector<int> numbers_guessed_right, vector<int> numbers_guessed_wrong, bool bingo) {
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
      while (J < numbers_guessed_wrong.size()) {
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
    if ((i + 1) % Number_of_terms_of_vector_v == 0) { // when Number_of_terms_of_vector_v = 3, i = 2 or 5 or 8 such that can directly jump to this branch; when Number_of_terms_of_vector_v = 4, i = 3 or 7 or 11 or 15 such that can directly jump to this branch
      cout << bingo_board[i] << endl;
    }
    else {
      cout << bingo_board[i];
    }
    i++;
  }
	bingo = check_bingo(numbers_guessed_right);
	if (bingo == true || (bingo == false && remaining_numbers_not_guessed.size() == 0)) {
		if (bingo == true) {cout << "Congratulations that you have made a bingo!!! You can enter 'N' to start a new game or 'Q' to quit the game.\n";}
		if (bingo == false && remaining_numbers_not_guessed.size() == 0) {cout << "I am sorry that you have lost the game. You can enter 'N' to start a new game or 'Q' to quit the game.\n";}
		char command;
		if (toupper(command) == 'Q') {
			cout << "Thank you for playing the game. Bye!\n";
			exit(1);
		}
		if (toupper(command) == 'N') {
			return main();
		}
	}
	
	if (bingo == false && remaining_numbers_not_guessed.size() > 2){
		cout << "You have already attempted to guess " << remaining_numbers_not_guessed.size() << " numbers in total.\nYou have already guessed correctly " << numbers_guessed_right.size() << " numbers and guessed wrongly " << numbers_guessed_wrong.size() << " numbers.\nEnter 'S' to save the current progress, 'Q' to quit, or 'N' to start a new game again.\n"
		char command;
		if (toupper(command) == 'S') {
			cout << "The game is saved.";
			save(remaining_numbers_not_guessed, numbers_guessed_right, numbers_guessed_wrong, Number_of_terms_of_vector_v, Number_of_attempts_allowed);
			return main();
		}
		if (toupper(command) == 'Q') {
			cout << "Thank you for playing the game. Bye!\n";
			exit(1);
		}
		if (toupper(command) == 'N') {
			return main();
		}
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
      if (remaining_number_of_attempts_allowed == 4) {
      cout << "You have 4 chances left. Wish you all the best. Good luck! \n";
    }
      if (remaining_number_of_attempts_allowed == 3) {
        cout << "You still have 3 chances left. Please seize the only chances left. I hope you can guess the correct number before using up the chances. \n";
      }
      if (remaining_number_of_attempts_allowed == 2) {
        cout << "You have only 2 chances left. Please seize the only chances left. \n";
      }
      else {
        cout << "You have only 1 chance left. Seems like you are rather unlucky now. I hope you can create the miracle of guessing the correct number with such a faint chance. \n";
      }
    }
    
    if (Number_of_terms_of_vector_v == 4) {
      cout << "Please make a guess (1 - 16). Press any number smaller than 1 or greater than 9 to save the progress of the bingo board before playing this round of 'guessing random number' game.\n";
    if (remaining_number_of_attempts_allowed == 7) {
      cout << "You have " << remaining_number_of_attempts_allowed << " chances left. Wish you all the best. Good luck! \n";
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
      remaining_number_of_attempts_allowed = 4; // reset the remaining number of attempts allowed to be 4 for 3x3 grid
      }
      else {
        remaining_number_of_attempts_allowed = 7; // reset the remaining number of attempts allowed to be 7 for 4x4 grid
      }
			return save(remaining_numbers_not_guessed, numbers_guessed_right, numbers_guessed_wrong, Number_of_terms_of_vector_v, Number_of_attempts_allowed);
      // pass int remaining_number_of_attempts_allowed, vector remaining_numbers_not_guessed, vector numbers_guessed_right, vector numbers_guessed_wrong to Savefile.txt
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

int main() {
vector<int>remaining_numbers_not_guessed;

vector<int>numbers_guessed_right;

vector<int>numbers_guessed_wrong;

int Number_of_terms_of_vector_v; // 3 or 4

int Number_of_attempts_allowed;

vector<string>bingo_board;

bool bingo = false;
  
  cout << "Welcome to this game! \nTry your luck and see if you are lucky or not today! \n\n"; //Welcoming
    // instruction code
    char instruction_code;
    cout << "Enter 'L' to load the previous saved game" << endl << "Enter 'S' to start a new game" << endl;
    cout << "Enter 'Q' to quit the game" << endl;
    cin >> instruction_code;
    while (toupper(instruction_code) != 'Q') {
      if (instruction_code != 'L' && instruction_code != 'S') {
        cout << "Invalid input. Please enter 'L', 'S' or 'Q' to continue. " << endl;
        cin >> instruction_code;
      }
    if (toupper(instruction_code) == 'L') {
      //to be implemented load from save
	    load(remaining_numbers_not_guessed, numbers_guessed_right, numbers_guessed_wrong, Number_of_terms_of_vector_v, Number_of_attempts_allowed);
	    run_guessing_random_number_game(remaining_numbers_not_guessed, Number_of_attempts_allowed, Number_of_terms_of_vector_v);
    }
    if (toupper(instruction_code) == 'S') {
      //run new game
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
        bingo_board = {"    1", "    2", "    3", "    4", "    5", "    6", "    7", "    8", "    9"};
        
        }
        else {
          Number_of_attempts_allowed = 10;
          bingo_board = {"    1", "    2", "    3", "    4", "    5", "    6", "    7", "    8", "    9", "   10", "   11", "   12", "   13", "   14", "   15", "   16"};
          
        }
      }
      //run the 'guessing random number' game (another function is called in the same function to print the bingo board)
      run_guessing_random_number_game(remaining_numbers_not_guessed, Number_of_attempts_allowed, Number_of_terms_of_vector_v); 
   
    }
    }
    if (toupper(instruction_code) == 'Q') {
      //Leave game
      cout << "Thank you! See you next time!!";
      exit(1);
    }

    return 0;
}
