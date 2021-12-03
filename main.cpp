//Main
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include <algorithm>
#include "run.h"
using namespace std;

int main() {
  cout << "Welcome to the game, you will be given a 3*3 matrix and you will be given 'n' times to guess per node, good luck and try to get a bingo!!" << endl;
  while (true) {
    cout << "Please choose an appropriate command to kick start: 'N' for new game; 'L' for load game; 'E' for exit" << endl;
    char command;
    cin >> command;
    if (command == 'N') {
      vector<int> to_be_guessed(9);
      vector<char> out_put(9);
      // start game
      cout << "Thank you for starting new game!" << endl;
      // initiate to_be_guessed
      srand(time(NULL));
      for (int i=0; i<9; i++) {
        int a = 1 + (rand()%9);
        to_be_guessed[i] = a;
      }
      // initiate out_put
      char temp_in_put = 'A'
      for (int i = 0; i<9 ; i++) {
        out_put[i] = temp_in_put;
        temp_in_put++
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

    else if (command == 'L') {
      vector<int> to_be_guessed(9);
      vector<char> out_put(9);
      // run load.cpp save at saved file
      // load cpp should be able to inut saved data into the vector out_put





      // then start game
      cout << "Thank you continuing the game, previously saved progress in " << endl;
      // run new to_be_guessed anyway
      srand(time(NULL));
      srand(time(NULL));
      for (int i=0; i<9; i++) {
        int a = 1 + (rand()%9);
        to_be_guessed[i] = a;
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


    else if (command == 'E') {
      // Exit, then break while loop
      cout << "Bye Bye, see you next time!" << endl;
      break;
    }


  return 0;
}
