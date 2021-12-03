//Main
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include <algorithm>
#include "run.h"
using namespace std;

void save(vector<int>& to_be_guessed, vector<char>& out_put) {
  ofstream fout("Savefile.txt");
  fout << "to_be_guessed ";
  for (int x=0; x < to_be_guessed.size(); x++) {
		if (x < to_be_guessed.size() - 1) {
			fout << to_be_guessed[x] << " ";
		}
		if (x == to_be_guessedd.size() - 1) {
			fout << to_be_guessed[x] << " " << 0 << endl;
		}
	}
  
  fout << "out_put ";
  for (int y=0; y < out_put.size(); y++) {
		if (y < out_put.size() - 1) {
			fout << out_put[y] << " ";
		}
		if (y == out_put.size() - 1) {
			fout << out_put[y] << " " << 0 << endl;
		}
	}
  
  fout << "#";
  fout.close();
  to_be_guessed.clear();
  out_put.clear();
}

void load(vector<int>& to_be_guessed, vector<char>& out_put) {
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
    
    fin >> vector_list_to_be_loaded;
    fin.close();
}
  
void run_guessing_random_number_game(vector<int>& to_be_guessed, vector<char>& out_put) {
  srand(time(NULL));
  for (int i=0; i<9; i++) {
    int a = 1 + (rand()%9);
    to_be_guessed[i] = a;
  }
      // initiate out_put
      char temp_in_put = 'A'
      for (int i = 0; i<9 ; i++) {
        out_put[i] = temp_in_put;
        temp_in_put++;
      }

      //showing the pre-any in-put grid
      cout << "Your current status: (New Game Version) " << endl;
      for (int i = 0; i<9; i=i+3) {
        for (int a = 0; a<3; a++) {
          cout << out_put[i+a] << " ";
        }
        cout << endl;
      }

      //how many nodes left?
      int number_of_node_guessed = 0;
      for (int i=0; i<9; i++) {
        if (out_put[i]>='A' && out_put[i]<='J') {
          number_of_node_guessed++;
        }
      }
      //main body
      int number_of_node_available = number_of_node_guessed;
      while (number_of_node_available>0) {
        char node_input;
        cout << "Please choose a location 'A-I' for the guessing, please don't pick either 'X':wrong or 'O':correct as those are your result. " << endl;
        cin >> node_input;
        srand(time(NULL));
        int max_guessing_chance = 1 + (rand()%9);
        int node_conversion = int(node_input) - int('A');
        if (run(to_be_guessed, max_guessing_chance, node_conversion)) {
          out_put[node_conversion] = 'O'; }
        else {
          out_put[node_conversion] = 'X';
        }
        cout << "Updates of your grid: " << endl;
        for (int i = 0; i<9; i=i+3) {
          for (int a = 0; a<3; a++) {
            cout << out_put[i+a] << " ";
          }
          cout << endl;
        }
        number_of_node_available--;
      }

      //result checking
      if (out_put[0] == 'O' && out_put[3] == 'O' && out_put[6] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      else if (out_put[1] == 'O' && out_put[4] == 'O' && out_put[7] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      else if (out_put[2] == 'O' && out_put[5] == 'O' && out_put[8] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      if (out_put[0] == 'O' && out_put[1] == 'O' && out_put[2] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      if (out_put[3] == 'O' && out_put[4] == 'O' && out_put[5] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      if (out_put[6] == 'O' && out_put[7] == 'O' && out_put[8] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      if (out_put[0] == 'O' && out_put[4] == 'O' && out_put[8] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      if (out_put[2] == 'O' && out_put[4] == 'O' && out_put[7] == 'O') {
        cout << "Congrats u got one or more than one bingo" << endl;
        break;
      }
      }

int main() {
  cout << "Welcome to this game! \nTry your luck and see if you are lucky or not today! \n\n"; //Welcoming
    // instruction code
    char instruction_code;
    cout << "Enter 'L'/'l' to load the previous saved game" << endl << "Enter 'N'/'n' to start a new game" << endl;
    cout << "Enter 'Q'/'q' to quit the game" << endl;
    cin >> instruction_code;
    while (toupper(instruction_code) != 'Q') {
      if (instruction_code != 'L' && instruction_code != 'S') {
        cout << "Invalid input. Please enter only 'L'/'l', 'N'/'n' or 'Q'/'q' to continue. " << endl;
        cin >> instruction_code;
      }
      if (toupper(instruction_code) == 'N') {
        vector<int> to_be_guessed(9);
        vector<char> out_put(9);
      // start game
        cout << "Thank you for starting a new game! Here we go! " << endl;
      // initiate to_be_guessed
        run_guessing_random_number_game(to_be_guessed, out_put);
    }

      if (toupper(instruction_code) == 'L') {
        vector<int> to_be_guessed(9);
        vector<char> out_put(9);
      // run load.cpp save at saved file
      // load cpp should be able to input saved data into the vector out_put
        load(to_be_guessed, out_put);
      // then start game
        cout << "Thank you for continuing the saved game. Here we go again. " << endl;
      // run new to_be_guessed anyway
        run_guessing_random_number_game(to_be_guessed, out_put); 
    }
      
  }

    if (toupper(instruction_code) == 'Q') {
      // Exit, then break while loop
      cout << "Bye Bye, see you next time!" << endl;
      exit(1);
    }

  return 0;
}
