#include <bits/stdc++.h>
 
using namespace std;

static const int BOARD_WIDTH = 4;
static const int BOARD_HEIGHT = 4;

int BOARD[BOARD_WIDTH][BOARD_HEIGHT] = {};

void make_board() {
    for (int i = 0; i < BOARD_WIDTH; ++i) {
       BOARD[0][i] = -1;
       BOARD[BOARD_HEIGHT - 1][i] = -1;
       BOARD[i][0] = -1;
       BOARD[i][BOARD_WIDTH - 1] = -1;
    }
    BOARD[BOARD_HEIGHT/2 - 1][BOARD_WIDTH/2 - 1] = 1;
    BOARD[BOARD_HEIGHT/2][BOARD_WIDTH/2] = 1;
    BOARD[BOARD_HEIGHT/2][BOARD_WIDTH/2 - 1] = 2;
    BOARD[BOARD_HEIGHT/2 - 1][BOARD_WIDTH/2] = 2;

}
int main() {
    make_board();
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) cout << BOARD[i][j];
        cout << endl;
    }

    return 0;
}
 

