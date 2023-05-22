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
    vector< vector<int> > mat;
    mat.resize(m);
    rep (i, m) {
        int k;
        cin >> k;
        mat[i].resize(k);
        rep(j, k) {
            int s;
            cin >> s;
            mat[i].push_back(s);
        }
    }
    vector<int> p;
    rep (i, m) {
        int p_i;
        cin >> p_i;
        p.push_back(p_i);
    }

    int ans = 0;
    for (int bit = 0; bit < (1<<n); bit++) {
        int can = 1;
        vector<int> on_off(n);
        rep (i, n) {
            if (bit & (1<<i)) on_off[i] = 1;
            else on_off[i] = 0;
        }
        rep (j, m) {
            int on = 0;
            rep (l, mat[j].size()) {
                if (on_off[mat[j][l] - 1]) on++;
            }
            if (on % 2 != p[j]) {
                can = 0;
                break;
            }
        }
        if (can) ans++;
    }
    cout << ans << endl;
}