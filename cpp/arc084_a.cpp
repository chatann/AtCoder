#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<ll> b(n);
    rep(i, n) cin >> b[i];
    sort(all(b));
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    sort(all(c));

    ll res = 0;
    rep(i, n) {
        ll iter_a = lower_bound(all(a), b[i]) - a.begin();
        ll iter_c = c.end() - upper_bound(all(c), b[i]);
        res += iter_a * iter_c;
    }

    cout << res << endl;

}