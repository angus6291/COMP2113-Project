//run.h
#ifndef RUN_H
#define RUN_H

void print_bingo_board(vector<string>bingo_board, int Number_of_terms_of_vector_v, vector<int>remaining_numbers_not_guessed, vector<int> numbers_guessed_right, vector<int> numbers_guessed_wrong);
void run_guessing_random_number_game(vector<int>remaining_numbers_not_guessed, int Number_of_attempts_allowed, int Number_of_terms_of_vector_v);

#endif
