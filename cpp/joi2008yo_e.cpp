#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    int R, C;
    cin >> R >> C;
    vector< vector<int> > a(R, vector<int>(C));
    rep (i, R) {
        rep (j, C) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1<<R); bit++) {
        vector< vector<int> > _a(R, vector<int>(C));
        rep (i, R) {
            rep (j, C) {
                _a[i][j] = a[i][j];
            }
        }
        rep (i, R) {
            if (bit & (1<<i)) {
                rep (j, C) {
                    _a[i][j] = abs(_a[i][j] - 1);
                }
            }
        }
        int total = 0;
        rep (j, C) {
            int a_j = 0;
            rep (i, R) {
                a_j += _a[i][j];
            }
            total += max(a_j, R - a_j);
        }
        ans = max(ans, total);
    }

    cout << ans << endl;
}