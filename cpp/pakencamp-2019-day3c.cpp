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
    int n, m;
    cin >> n >> m;
    vector< vector<ll> > A(n, vector<ll>(m));
    rep (i, n) {
        rep (j, m) {
            cin >> A[i][j];
        }
    }
    ll ans = 0;
    rep (t1, m - 1) {
        reps (t2, t1 + 1, m) {
            ll score = 0;
            rep (i, n) {
                score += max(A[i][t1], A[i][t2]);
            }
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
}