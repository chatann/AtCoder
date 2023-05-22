#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
const ll INF_L = 1LL << 60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = LLONG_MAX;
    for (int bit = 0; bit < (1<<n); bit++) {
        vector<ll> b(n);
        rep(i, n) {
            b[i] = a[i];
        }

        int num = 0;
        rep (i, n) {
            if (bit & (1<<i)) num++;
        }
        if (num < k) continue;

        ll cost = 0;
        rep(i, n) {
            if (i > 0 && (bit & (1<<i))) {
                rep(j, i) {
                    if (b[j] >= b[i]) {
                        cost += b[j] - b[i] + 1;
                        b[i] = b[j] + 1;
                    }
                }
            }
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;
}