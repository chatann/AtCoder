#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector< vector<bool> > mat(5001, vector<bool>(5001));
    rep (i, n) {
        cin >> x[i] >> y[i];
        mat[x[i]][y[i]] = true;
    }

    int ans = 0;
    rep (i, n) {
        rep (j, n) {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            if (x[i] - dy < 0 || x[i] - dy > 5000 || x[j] - dy < 0 || x[j] - dy > 5000 || y[i] + dx < 0 || y[i] + dx > 5000 || y[j] + dx < 0 || y[j] + dx > 5000) continue;
            if (mat[x[j] - dy][y[j] + dx] && mat[x[i] - dy][y[i] + dx]) {
                int square = dx * dx + dy * dy;
                ans = max(ans, square);
            }
        }
    }
    cout << ans << endl;
}