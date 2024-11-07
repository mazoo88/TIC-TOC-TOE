#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

bool GameEnded(vector <char> board){

    if (board[2] == board[7] && board[7] == board[12])
        return true;
    if (board[2] == board[6] && board[6] == board[10])
        return true;
    if (board[2] == board[8] && board[8] == board[14])
        return true;
    if (board[6] == board[7] && board[7] == board[8])
        return true;
    if (board[10] == board[11] && board[11] == board[12])
        return true;
    if (board[11] == board[12] && board[12] == board[13])
        return true;
    if (board[12] == board[13] && board[13] == board[14])
        return true;

    return false;
}




int minimax (int &x, vector<char>board, char symbol_1, char symbol_2, bool maximize, int nMoves){

    if (GameEnded(board))
        if (maximize) return -1;
        else return 1;
    if (nMoves >= 9) return 0;
    int bestScore = (maximize) ? -2:2;
    for (int i = 0; i<15; ++i)
        if (isdigit(board[i])) {
            char temp = board[i];
            board[i] = (maximize) ? toupper(symbol_1) : toupper(symbol_2);
            int score = minimax(x, board, symbol_1, symbol_2, !maximize, nMoves + 1);
            board[i] = temp;
            if (maximize && score > bestScore)
                bestScore = score;
            else if (!maximize && score < bestScore)
                bestScore = score;
        }
    return bestScore;
}



// Set player symbol and name as Random Computer Player
AiPlayer::AiPlayer (char symbol):Player(symbol) {
    this->name = "AI";
    cout << "My names is " << name << endl;
}



void AiPlayer::smart_move (int& x, char* currentBoard, char symbol_1, char symbol_2, int nMoves) {

    vector <char> board(15);
    for (int i=0; i<15; ++i)
        board[i] = currentBoard[i];

    int bestScore = -2;
    for (int i=0; i<15; ++i) {
        if (isdigit(board[i])) {
            char temp = board[i];
            board[i] = toupper(symbol_1);
            int score = minimax(x, board, symbol_1, symbol_2, false, nMoves + 1);
            board[i] = temp;
            if (score > bestScore) {
                bestScore = score;
                x = board[i] - 48 ;
            }
        }
    }
}