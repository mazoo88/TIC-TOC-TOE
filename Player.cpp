#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move
void Player::get_move (int& x) {
    cout << "\nPlease choose one of the remaining squares: ";
    cin >> x;
}

void Player::get_moves(int& x, int& y)
{
    cout << "\nPlease choose one of the remaining squares: ";
    cin >> x >> y;
}


// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}
