#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;

ll path (ll ent, ll a, ll b, ll exit) {
    return abs(a - ent) + abs(b - exit) + b - a;
}

int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    rep (i, n) {
        cin >> A[i] >> B[i];
    }
    
    ll ans = 1LL << 60;
    rep (i, n) {
        rep (j, n) {
            ll cur = 0;
            rep (k, n) {
                cur += path(A[i], A[k], B[k], B[j]);
            }
            ans = min(ans, cur);
        }
    }

    cout << ans << endl;
}