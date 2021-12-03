//for running the game and output status per every guess
//first of all seperate into either 3*3 or 4*4
//vector will be set for dynamic storage
#include <iostream>
#include <string>
#include <vector>
#include "guessing_random_number.h"
using namespace std;

void run_guessing_random_number_game(vector<int>& to_be_guessed, vector<char>& out_put) { // only run once
     //showing the pre-any in-put bingo board
      cout << "Your current status: (New Game Version) " << endl;
      for (int i = 0; i<9; i=i+3) {
        for (int a = 0; a<3; a++) {
          cout << out_put[i+a] << "   ";
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
        cout << "Please input letters from A to I for the guessing. Do not pick either 'X' (wrong) or 'O' (correct), as those are your result. " << endl;
        cin >> node_input;
        int max_guessing_chance = 3;
        int node_conversion = int(node_input) - int('A');
        if (run(to_be_guessed, max_guessing_chance, node_conversion)) {out_put[node_conversion] = 'O';}
        else {out_put[node_conversion] = 'X';}
        cout << "Your updated grid: " << endl;
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
