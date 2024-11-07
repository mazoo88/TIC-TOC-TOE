// Class definition for PyramidBoard class
// Author:  Ashraf Alaa
// Date:    6/12/2023

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
PyramidBoard::PyramidBoard () {
    n_rows = 1; n_cols = 16;
    board = new char*[n_rows];
    board [0] = new char[n_cols];
    for (int i =0,j=1 ; i < 16; ++i)
        if ( (i < 6 && i != 2) || i == 9)
            board [0][i] = ' ';
        else
            {board [0][i] = j + 48; j++;}
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool PyramidBoard::update_board (int x, int y, char mark){
   // Only update if move is valid
    if (!(x < 0 || x > 9)) {

        if (x == 1 && isdigit(board[0][2])) {
            board[0][2] = toupper(mark);
            ++n_moves; return true;
        }

        else if (x < 5 && isdigit(board[0][x + 4])) {
            board[0][x + 4] = toupper(mark);
            ++n_moves; return true;
        }

        else if (isdigit(board[0][x + 5])) {
            board[0][x + 5] = toupper(mark);
            ++n_moves; return true;
        }
    }
    else
        return false;
}

// Display the board and the pieces on it
void PyramidBoard::display_board() {
    system("cls");
    for (int i = 1; i < 16; ++i) {
        cout << ' ' << board [0][i-1] ;
        if (i == 1 || i == 4) cout << "  ";
        else if (i%5) cout << " |";
        if (!(i%5)) cout << '\n';
    }
    cout << endl;
}

// Returns true if there is any winner
bool PyramidBoard::is_winner() {

    if (board[0][2] == board[0][7] && board[0][7] == board[0][12])
        return true;
    if (board[0][2] == board[0][6] && board[0][6] == board[0][10])
        return true;
    if (board[0][2] == board[0][8] && board[0][8] == board[0][14])
        return true;
    if (board[0][6] == board[0][7] && board[0][7] == board[0][8])
        return true;
    if (board[0][10] == board[0][11] && board[0][11] == board[0][12])
        return true;
    if (board[0][11] == board[0][12] && board[0][12] == board[0][13])
        return true;
    if (board[0][12] == board[0][13] && board[0][13] == board[0][14])
        return true;

    return false;
}

// Return true if 9 moves are done and no winner
bool PyramidBoard::is_draw() {
    return (n_moves == 9 && !is_winner());
}


bool PyramidBoard::game_is_over () {
    return n_moves >= 9;
}


int PyramidBoard::nMoves(){
    return n_moves;
}

char* PyramidBoard::current_board() {
    return board[0];
}