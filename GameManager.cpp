#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;


GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

GameManager::GameManager(Board* bPtr, Player* playerPtr, AiPlayer* playerPtr2) {
    boardPtr = bPtr;
    players[0] = playerPtr;
    ai = playerPtr2;
}


void GameManager::run(){
    int x;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x);
            while (!boardPtr->update_board (x , 0, players[i]->get_symbol())){
                players[i]->get_move(x);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
};

void GameManager::run5() {
    int x,y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_moves(x,y);
            while (!boardPtr->update_board (x,y , players[i]->get_symbol())){
                players[i]->get_moves(x,y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
        }
    }
}

void GameManager::runAi() {
    int x;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {

            players[0]->get_move(x);
            while (!boardPtr->update_board (x, 0, players[0]->get_symbol())){
                players[0]->get_move(x);
            }

            boardPtr->display_board();

            if (boardPtr->is_winner()){
                cout  << players[0]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        ai->smart_move(x, boardPtr->current_board(), ai->get_symbol(), players[0]->get_symbol(), boardPtr->nMoves());
        while (!boardPtr->update_board (x, 0, ai->get_symbol())){
            ai->smart_move(x, boardPtr->current_board(), ai->get_symbol(), players[0]->get_symbol(), boardPtr->nMoves());
        }

        boardPtr->display_board();

        if (boardPtr->is_winner()){
            cout  << ai->to_string() << " wins\n";
            return;
        }

        if (boardPtr->is_draw()){
            cout << "Draw!\n";
            return;
        }
    }
}

