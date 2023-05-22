#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > rel(n, vector<int>(n));
    rep (i, m) {
        int x, y;
        cin >> x >> y;
        rel[x - 1][y - 1] = 1;
    }
    int ans = 0;
    for (int bit = 0; bit < (1<<n); bit++) {
        int can = 1;
        vector<int> vec;
        rep (i, n) {
            if (bit & (1<<i)) vec.push_back(i);
        }
        rep (i, vec.size() - 1) {
            reps (j, i + 1, vec.size()) {
                if (!rel[vec[i]][vec[j]]) {
                    can = 0;
                    break;
                }
            }
        }
        int num = vec.size();
        if (can) ans = max(ans, num);
    }
    cout << ans << endl;
}