#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = A * X + B * Y;
    rep(i, 2 * max(X, Y) + 1) {
        int cost = A * max(X - i/2, 0) + B * max(Y - i/2, 0) + C * i;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}