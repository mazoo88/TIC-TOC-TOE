#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
#include <string>
#include <deque>
#include <bits/stdc++.h>

using namespace std;
deque<deque<char>>d_cols(7);

class Board {
protected:
   int n_rows,  n_cols;
   char** board;
   int  n_moves = 0;

public:
   // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   // virtual bool update_board (int x, char symbol)=0;
    virtual bool update_board (int x, int y, char symbol)=0;
   // Returns true if there is any winner
   // either X or O
   // Written in a complex way. DO NOT DO LIKE THIS.
   virtual bool is_winner() = 0;
   // Return true if all moves are done and no winner
   virtual bool is_draw() = 0;
   // Display the board and the pieces on it
   virtual void display_board() = 0;
   // Return true if game is over
   virtual bool game_is_over() = 0;
   // Return the current number of moves
   virtual int nMoves() = 0;
   // return a copy of the board in dynamically created array
   virtual char* current_board()=0;
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
   X_O_Board ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool is_draw();
   bool game_is_over();
   int nMoves();
   char* current_board();
};

///////////////////////////////////////////
// This class represents a 3 x 5 board
// used in Pyramid version of X_O game
class PyramidBoard:public Board {
public:
    PyramidBoard();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int nMoves();
    char* current_board();
};

///////////////////////////////////////////
// This class represents a 6 x 7 board
// used in four in row version of X_O game
class Four_in_a_row_Board : public Board {
public:
    Four_in_a_row_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int nMoves();
    char* current_board();
    char px = 0, py = 0;
};
///////////////////////////////////////////
// This class represents a 5 x 5 board
// used in 5 by 5 version of X_O game
class FiveByFive:public Board {
private :
    int count_X, count_O;
public:
    FiveByFive ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    char* current_board();
    int nMoves();
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
    protected:
        string name;
        char symbol;
    public:
        // Two constructors to initiate player
        // Give player a symbol to use in playing
        // It can be X or O or others
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2
        Player (char symbol); // Needed for computer players
        Player (int order, char symbol);
        // Get desired move: x y (each between 0 and 2)
        // Virtual (can change for other player types)
        virtual void get_moves(int& x, int & y);
        virtual void get_move(int& x);
        // Give player info as a string
        string to_string();
        // Get symbol used by player
        char get_symbol();
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x in range of the board
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        RandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x);
        void get_moves(int& x, int&y);
};

///////////////////////////////////////////
// This class represents a random computer player
// that smart move for pyramid and classic X O
// If invalid, game manager asks to regenerate
class AiPlayer: public Player {

public:
    // Take a symbol and pass it to parent
    AiPlayer(char symbol);
    // Generate the best move
    void smart_move(int& x, char* currentBoard, char symbol1, char symbol2, int nMoves);
};

///////////////////////////////////////////
class GameManager {
    protected:
        Board* boardPtr;
        Player* players[2];
        AiPlayer* ai;
    public:
        GameManager(Board*, Player* playerPtr[2]);
        GameManager(Board*, Player* playerPtr, AiPlayer* playerPtr2);

        // uses two players (humans and or random)
        void run();
        void run5();
        // uses the Ai player
        void runAi();
        // This method creates board and players
        // It displays board
        // While True
        //   For each player
        //      It takes a valid move as x
        //      It updates board and displays the results
        //      If winner, declare so and end
        //      If draw, declare so and end

};
///////////////////////////////////////////

#endif
