#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> S(n);
    rep(i, n) cin >> S[i];
    int q;
    cin >> q;
    vector<long long> T(q);
    rep(i, q) cin >> T[i];
    int ans = 0;
    rep(i, q) {
        if (*lower_bound(all(S), T[i]) == T[i]) ans++;
    }
    cout << ans << endl;
}