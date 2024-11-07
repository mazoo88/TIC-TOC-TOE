#include "BoardGame_Classes.hpp"
#define l '\n'
#define w while
#define ll long long

FiveByFive::FiveByFive() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool FiveByFive::update_board (int x, int y, char mark) {
    if (!(x < 0 ||x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void FiveByFive::display_board() {
    system("cls");
    for (int i=0 ; i <= 4 ; i++) {
        cout << l<<"| ";
        for (int j=0 ; j <= 4 ; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout <<l<< "----------------------------------------------";
    }
    cout << l;
}

bool FiveByFive::is_winner() {
    if(n_moves==24)
    {
        char unknown;
        for (int i=0 ; i<=2 ; i++)
        {
            for(int j=0 ; j<=2 ; j++)
            {
                unknown =board[i][j] & board[i+1][j+1] & board[i+2][j+2];   // each 3 in diagonal
                if( unknown=='X') count_X++;
                else if( unknown=='O') count_O++;

                unknown =board[i][4-j] & board[i+1][3-j] & board[i+2][2-j];   // same loop
                if( unknown=='X') count_X++;
                else if( unknown=='O') count_O++;
            }
        }
        for (int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                unknown = board[i][j] & board[i][j+1] & board[i][j+2];   // each row
                if( unknown=='X') count_X++ ;
                else if( unknown=='O') count_O++;

                unknown =board[j][i] & board[j+1][i] & board[j+2][i];   //each column
                if( unknown=='X') count_X++;
                else if( unknown=='O') count_O++;
            }
        }

        if (count_X==count_O){
            cout  <<"Draw\n";
        }
        else
            return(count_X>count_O); // X is winner == true   // O  --> false
    }
    return false ;
}

int FiveByFive::nMoves() {
    return n_moves;
}

bool FiveByFive::game_is_over (){
    return n_moves >= 24;
}

bool FiveByFive::is_draw() {
    return (count_X == count_O);
}

char* FiveByFive::current_board() {
    return board[0];
}