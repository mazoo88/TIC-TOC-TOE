#include <iostream>
#include "GameManager.cpp"
#include "Player.cpp"
#include "AiPlayer.cpp"
#include "RandomPlayer.cpp"
#include "X_O_Board.cpp"
#include "PyramidBoard.cpp"
#include "Four in row .cpp"
#include "FiveByFive.cpp"
using namespace std;

int main() {

    cout << "Welcome to FCAI X O variations Game\n"
         << "Choose your favorite variation from the menu\n"
         << "1) Classic.\n2) Pyramid.\n3) Connect Four.\n4) 5x5.\n";

    int variation = 0, mood = 0;
    while (variation > 4 || variation < 1)
        cin >> variation;

    Player *players[2];
    AiPlayer* player2;
    players[0] = new Player(1, 'x');

    while (mood > 3 || mood < 1) {
        cout << "1)Two players\n2)Random Computer" << (variation == 2 ? "\n3)Ai\n" : "\n");
        cin >> mood;
    }

    switch (mood){

        case 1:
            players[1] = new Player(2, 'o');
            break;

        case 2:
            players[1] = new RandomPlayer('o', 9);
            break;

        case 3:
            if (variation == 2)
                player2 = new AiPlayer ('o');
    }

    Board* board;
    switch (variation) {

        case 1:
        board = new X_O_Board(); break;

        case 2:
            board = new PyramidBoard(); break;

        case 3:
            board = new Four_in_a_row_Board(); break;

        case 4:
            board = new FiveByFive();
    }

    if (mood == 3 && variation == 2){
        GameManager Game(board, players[0], player2);
        Game.runAi();
    }

    else {
        GameManager Game(board, players);
        if (variation == 4) Game.run5();
        else Game.run();
    }

    system("pause");
}