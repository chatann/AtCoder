#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> p(n + 1);
    reps(i, 1, n + 1) cin >> p[i];
    sort(all(p));

    vector<ll> pp;
    rep(i, n + 1) {
        rep(j, n + 1) {
            if (p[i] + p[j] <= m) pp.push_back(p[i] + p[j]);
        }
    }

    sort(all(pp));
    ll score = 0;
    rep(i, pp.size()) {
        ll ok = -1, ng = pp.size();
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (pp[i] + pp[mid] <= m) ok = mid;
            else ng = mid;
        }
        score = max(score, pp[i] + pp[ok]);
    }

    cout << score << endl;
}
