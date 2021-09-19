#include <bits/stdc++.h>
 
using namespace std;

static const int BOARD_WIDTH = 4;
static const int BOARD_HEIGHT = 4;
int my_piece;

int BOARD[BOARD_WIDTH][BOARD_HEIGHT] = {};


void make_board() {
    for (int i = 0; i < BOARD_WIDTH; ++i) {
//       BOARD[0][i] = 0; 
//       BOARD[BOARD_HEIGHT - 1][i] = 0;
//       BOARD[i][0] = 0; 
//       BOARD[i][BOARD_WIDTH - 1] = 0;
       BOARD[0][i] = 1;
       BOARD[BOARD_HEIGHT - 1][i] = 1;
       BOARD[i][0] = 1; 
       BOARD[i][BOARD_WIDTH - 1] = 1;

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
                    check_y += i;
                    check_x += j;
                    if (check_x < 0 || check_x > BOARD_WIDTH - 1) break;
                    if (check_y < 0 || check_y > BOARD_HEIGHT - 1) break;
                    if (BOARD[check_y][check_x] == my_piece) return true;
                    
                }
            }
        }
    }
    return false;
}
void set_piece(int y, int x) {
    int check_x, check_y;
    for (int i = -1; i <= 1 ; ++i) {
        for (int j = -1; j <= 1; ++j) {
            check_y = y + i;
            check_x = x + j;
            if (check_x < 0 || check_x > BOARD_WIDTH - 1) continue;
            if (check_y < 0 || check_y > BOARD_HEIGHT - 1) continue;
            while (BOARD[check_y][check_x] == -my_piece) {
                check_y += i;
                check_x += j;
                if (check_x < 0 || check_x > BOARD_WIDTH - 1) continue;
                if (check_y < 0 || check_y > BOARD_HEIGHT - 1) continue;
                if (BOARD[check_y][check_x] == my_piece) {
                    while (!(y == check_y && x == check_x)) {
                        check_y -= i;
                        check_x -= j;
                        BOARD[check_y][check_x] = my_piece; // reverse + set;
                        cout << "while2" << endl;

                    }
                }
                cout << "while1" << endl;
            }
            
        }
    } 
}
int count_0 = 0;
// 0 の個数が0のとき、ゲーム終了か、2回4回のパスが続いたら負け。
bool available_to_set() {
    bool check = false;
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (BOARD[i][j] == 0) {
                count_0 += 1;
                if (is_enable_to_set(i, j)) {
                    cout << "true" << endl;
                    check = true;
                } 
            
            }
        }
    }
    
    cout << "false" << endl;

    return check;
}

int main() {
    // 配置座標
    int x, y;
    make_board();
    decorate_board();
    my_piece = -1; // default white

    cout << "先手 : 白, 後手 : 黒" << endl;
    while (1) {
         if (count_0 == 0) {
            cout << "ゲーム終了" << endl;
            break;
         }
         if (!available_to_set()) {
             cout << "置くところがありません。" << endl;
             decorate_board();
             my_piece = -my_piece;
             continue;
         }
         do {
             if (my_piece == -1) cout << "白の手番です。" << endl;
             else cout << "黒の手番です。" << endl;
             cout << "配置場所を入力してください。" << endl;
             cin >> y >> x;
        
         } while(!is_enable_to_set(y, x));
         cout << "true" << endl;
         set_piece(y, x);
         decorate_board();
         my_piece = -my_piece;

    }


    return 0;
}
 

