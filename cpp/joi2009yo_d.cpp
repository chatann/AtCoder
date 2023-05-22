#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;
using Field = vector<vector<int> >;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int m, n;

bool seen[100][100];
void dfs(Field field, int h, int w, int counter, vector<int> &num) {
    seen[h][w] = true;
    rep(i, 4) {
        int nh = h + dy[i];
        int nw = w + dx[i];
        if (nh < 0 || nh >= n || nw < 0 || nw >= m) continue;
        if (field[nh][nw] == 0) continue;
        if (seen[nh][nw]) continue;
        dfs(field, nh, nw, counter + 1, num);
    }
    seen[h][w] = false;
    num.push_back(counter);
}

int main() {
    cin >> m >> n;
    Field field(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> field[i][j];
        }
    }
    int res = 0;
    rep(i, n) {
        rep(j, m) {
            int counter = 1;
            vector<int> num(200000);
            if (field[i][j]) dfs(field, i, j, counter, num);
            int cur = *max_element(all(num));
            res = max(res, cur);
        }
    }
    cout << res << endl;
}
