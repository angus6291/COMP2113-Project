//run.cpp for run game!!
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream> // for file input and output ('saved game')
#include <cstdlib> // for srand(), rand()
#include <algorithm>
#include "run.h"
using namespace std;

bool run(vector<int> to_be_guessed, int node_conversion) { // return true if guessed successfully, false if not guessed successfully
  int correct_ans = to_be_guessed[node_coversion];
  cout << "You have only 3 chances". Good Luck." << endl;
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
  cout << "I am sorry that your chances are used up and you still haven't guessed the right letter. " << endl;
  return false;
}
}
