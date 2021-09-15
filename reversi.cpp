#include <bits/stdc++.h>
 
using namespace std;

static const int BOARD_WIDTH = 4;
static const int BOARD_HEIGHT = 4;
int my_piece;

int BOARD[BOARD_WIDTH][BOARD_HEIGHT] = {};


void make_board() {
    for (int i = 0; i < BOARD_WIDTH; ++i) {
       BOARD[0][i] = 0; 
       BOARD[BOARD_HEIGHT - 1][i] = 0;
       BOARD[i][0] = 0; 
       BOARD[i][BOARD_WIDTH - 1] = 0;
    }
    BOARD[BOARD_HEIGHT/2 - 1][BOARD_WIDTH/2 - 1] = 1;
    BOARD[BOARD_HEIGHT/2][BOARD_WIDTH/2] = 1;
    BOARD[BOARD_HEIGHT/2][BOARD_WIDTH/2 - 1] = -1;
    BOARD[BOARD_HEIGHT/2 - 1][BOARD_WIDTH/2] = -1;

}
void decorate_board() {
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            switch (BOARD[i][j]) {
                case 0: 
                    cout << ".";
					break;
                case -1:
                    cout << "○";
                    break;
                case 1:
                    cout << "●";
                    break; 
                default:
                    break;
                
            }
        }
        cout << endl;
    }
}
// C -> int C++ -> bool
bool is_enable_to_set(int y, int x) {
    if (BOARD[y][x] == 0) {
        // 縦横判定 1マスずつ合計9マス確認
        int check_x, check_y;
        for (int i = -1; i <= 1; ++i) { // row
            for (int j = -1; j <= 1; ++j) { // column 
                check_x = x + j;
                check_y = y + i;
                if (check_x < 0 || check_x > BOARD_WIDTH - 1) continue;
                if (check_y < 0 || check_y > BOARD_HEIGHT - 1) continue;
                while (BOARD[check_y][check_x] == -my_piece) {
                    // opponent's piece
                    if (check_x < 0 || check_x > BOARD_WIDTH - 1) break;
                    if (check_y < 0 || check_y > BOARD_HEIGHT - 1) break;
                    
                    if (BOARD[check_y][check_x] == my_piece) return true;

                    check_y += i;
                    check_x += j;
                    
                }
            }
        }
    }
    return false;
}

int main() {
    // 配置座標
    int x, y;
    make_board();
    decorate_board();
    my_piece = -1; // default white

//    for (int i = 0; i < BOARD_HEIGHT; ++i) {
//        for (int j = 0; j < BOARD_WIDTH; ++j) cout << BOARD[i][j];
//        cout << endl;
//    }

    do {
        cout << "配置場所を入力してください。" << endl;
        cin >> x >> y;
    } while(!is_enable_to_set(y, x))

    return 0;
}
 

