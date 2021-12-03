//run.cpp for run game!!
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include <algorithm>
#include "run.h"
using namespace std;

bool run(vector<int>& to_be_guessed, int max_guessing_chance, int node_conversion) {
  int correct_ans = to_be_guessed[node_coversion];
  cout << "Your maximum guessing chances: " << max_guessing_chance << ". Good Luck." << endl;
  for (i=1; max_guessing_chance>=i; i++) {
    int user_input_for_node;
    cin >> user_input_for_node;
    if(user_input_for_node == correct_ans) {
      cout << "Congrats, for the selected node, u hv the right ans within maximum guessing chance, 'O' will be shown in the board" << endl;
      return true;
    if(user_input_for_node != correct_ans && max_guessing_chance != i) {
      cout << "Please retry guessing." << endl;
    }
    }
  }
  cout << "Unfortunately, for the selected node, u doesn't hv the right ans within maximum guessing chance, 'X' will be shown in the board" << endl;
  return false;
}
