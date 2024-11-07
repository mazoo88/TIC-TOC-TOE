#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"

using namespace std;

// Set the board
X_O_Board::X_O_Board () {
   n_rows = 1, n_cols = 9;
   board = new char * [n_rows];
   board[0] = new char[n_cols];
   for (int i = 0, j=49; i < n_cols; ++i){
       board[0][i] = j; j++;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (int x, int y, char mark){

    // Only update if move is valid
   if (!(x < 1 || x > 9) && (isdigit(board[0][x-1]))) {
      board[0][x-1] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
      system("cls");
    for (int i = 1; i < 10; ++i) {
        cout << ' ' << board [0][i - 1] ;
        if (i%3) cout << " |";
        if (!(i%3) && i < 7) cout << "\n-----------\n";
        if (!(i%3) && i > 6) cout << "\n\n";
    }
}

// Returns true if there is any winner
// either X or O.
bool X_O_Board::is_winner() {

    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return true;
    if (board[0][0] == board[0][3] && board[0][3] == board[0][6])
        return true;
    if (board[0][0] == board[0][4] && board[0][4] == board[0][8])
        return true;
    if (board[0][1] == board[0][4] && board[0][4] == board[0][7])
        return true;
    if (board[0][2] == board[0][4] && board[0][4] == board[0][6])
        return true;
    if (board[0][2] == board[0][5] && board[0][5] == board[0][8])
        return true;
    if (board[0][3] == board[0][4] && board[0][4] == board[0][5])
        return true;
    if (board[0][6] == board[0][7] && board[0][7] == board[0][8])
        return true;

    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}

int X_O_Board::nMoves(){
    return n_moves;
}

char* X_O_Board::current_board() {
    return board[0];
}
