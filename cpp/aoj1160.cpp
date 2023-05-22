#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;

const int dh[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dw[8] = {0, -1, 0, 1, 1, -1, 1, -1};

int W, H;
vector<vector<int> > field;

void dfs(int h, int w) {
    field[h][w] = 0;
    rep(i, 8) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == 0) continue;
        dfs(nh, nw);
    }
}

int main() {
    while (cin >> W >> H) {
        if (W == 0 || H == 0) break;
        field.assign(H, vector<int>(W, 0));
        rep(i, H) rep(j, W) cin >> field[i][j];
        int count = 0;
        rep(i, H) {
            rep(j, W) {
                if (field[i][j] == 0) continue;
                dfs(i, j);
                count++;
            }
        }
        cout << count << endl;
    }
}
