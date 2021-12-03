//guessing_random_number.cpp
//bingo board: only 3x3 bingo board
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include "guessing_random_number.h"
using namespace std;

void run_guessing_random_number_game(vector<int> to_be_guessed, vector<char> out_put) { // only run once
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
        if (run(to_be_guessed, node_conversion) == true) {out_put[node_conversion] = 'O';}
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

bool run(vector<int> to_be_guessed, int node_conversion) { // return true if guessed successfully, false if not guessed successfully
  int correct_ans = to_be_guessed[node_conversion];
  cout << "You have only 3 chances. Good Luck." << endl;
  int i=3;
  while (i>0) {
    int user_input_for_node;
    cin >> user_input_for_node;
    if(user_input_for_node == correct_ans) {
      cout << "Congratulations! You have guessed the right letter within the given chances!" << endl;
      return true;
      break;
    }
    if(user_input_for_node != correct_ans && i < 3) {
      cout << "Please retry guessing." << endl;
    }
    i--;
  }
  
  if (i==0) {
  cout << "I am sorry that your chances are used up. You still haven't guessed the right letter. " << endl;
  return false;
  break;
}
}
