#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;

void queen_move(vector< vector<int> > &chessboard, int x, int y) {
    rep(j, 8) {
        chessboard[x][j] = 1;
        chessboard[j][y] = 1;
        if (x + j <= 7) {
            if (y + j <= 7) chessboard[x + j][y + j] = 1;
            if (y - j >= 0) chessboard[x + j][y - j] = 1;
        }
        if (x - j >= 0) {
            if (y + j <= 7) chessboard[x - j][y + j] = 1;
            if (y - j >= 0) chessboard[x - j][y - j] = 1;
        }
    }
}

int main() {
    int k;
    cin >> k;
    vector< vector<int> > chessboard(8, vector<int>(8));
    vector< pair<int, int> > queen(k);
    rep(i, k) {
        cin >> queen[i].first >> queen[i].second;
        queen_move(chessboard, queen[i].first, queen[i].second);
    }

    vector<int> order1(8), order2(8);
    rep(i, 8) {
        order1[i] = i;
        order2[i] = i;
    }
    int can = 0;
    do {
        do {
            vector< vector<int> > test(8, vector<int>(8));
            rep(i, 8) {
                rep(j, 8) {
                    test[i][j] = chessboard[i][j];
                }
            }
            vector< vector<int> > queen_pos(8, vector<int>(8));
            rep(i, k) {
                queen_pos[queen[i].first][queen[i].second] = 1;
            }
            int l = 0;
            rep(i, 8) {
                rep(j, 8) {
                    if (!test[order1[i]][order2[j]]) {
                        queen_pos[order1[i]][order2[j]] = 1;
                        queen_move(test, order1[i], order2[j]);
                        l++;
                    }
                }
            }
            if (k + l == 8) {
                rep(i, 8) {
                    rep(j, 8) {
                        if(queen_pos[i][j]) cout << "Q";
                        else cout << ".";
                    }
                    cout << "\n";
                }
                can = 1;
                break;
            }
        } while (next_permutation(all(order2)));
        if (can) break;
    } while (next_permutation(all(order1)));
}