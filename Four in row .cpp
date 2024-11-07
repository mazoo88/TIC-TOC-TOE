#include "BoardGame_Classes.hpp"
#include <iostream>
#include <deque>
using namespace std;
// Set the board
Four_in_a_row_Board::Four_in_a_row_Board () {
    n_rows =6; n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Four_in_a_row_Board::update_board (int y, int z, char mark){
    int x;
    // Only update if move is valid
    for (int i = 5; i >=0 ; i--) {
        if (board[i][y]==0){
            x=i;
            // board[x][y]=1;
            break;
        }
    }
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        px=x;py=y;
        //board[x][y]=1;
        return true;
    }
    else
        px=x;py=y;
    return false;
}

// Display the board and the pieces on it
void Four_in_a_row_Board::display_board() {
    system("cls");
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "("<<j<<")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n---------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Four_in_a_row_Board::is_winner() {
    char s=px,r=py;

    for (int i = 0; i < 3; ++i) {
        if (board[i][r]&&board[i][r]==board[i+1][r]&&board[i+1][r]
            &&board[i][r]==board[i+2][r]&&board[i+2][r]
            &&board[i][r]==board[i+3][r]&&board[i+3][r]){
            return true;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (board[s][i]&&board[s][i]==board[s][i+1]&&board[s][i+1]
            &&board[s][i]==board[s][i+2]&&board[s][i+2]
            &&board[s][i]==board[s][i+3]&&board[s][i+3]){
            return true;
        }
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i+3<6&&j+3<7){
                if (board[i][j] && board[i + 1][j + 1]
                    &&board[i + 2][j + 2]&&board[i+3][j+3]
                    &&board[i][j]==board[i + 1][j + 1]
                    &&board[i][j]==board[i + 2][j + 2]
                    &&board[i][j]== board[i + 3][j + 3]){
                    return true;
                }
            }
        }
    }
    for (int i = 0; i <6; i++) {
        for (int j = 6; j >=0; j--) {
            if (i+3<6&&j-3>=0){
                if (board[i][j] && board[i + 1][j - 1]
                    &&board[i + 2][j - 2]&&board[i+3][j-3]
                    &&board[i][j]==board[i + 1][j - 1]
                    &&board[i][j]==board[i + 2][j - 2]
                    &&board[i][j]==board[i + 3][j - 3]){
                    return true;
                }
            }
        }
    }

    return false;
}

// Return true if 9 moves are done and no winner
bool Four_in_a_row_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_in_a_row_Board::game_is_over () {
    return n_moves >= 42;
}

int Four_in_a_row_Board::nMoves() {
    return n_moves;
}

char* Four_in_a_row_Board::current_board() {
    return board[0];
}