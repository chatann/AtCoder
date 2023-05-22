#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

ll n;

bool D(ll height, vector<ll>& h, vector<ll>& s) {
    rep(i, n) {
        if (height - h[i]) / s[i] < t) 
    }
}

bool C(ll height, vector<ll>& h, vector<ll>& s) {
    ll ok_ = 0, ng_ = LLONG_MAX;
    while (abs(ok_ - ng_) > 1) {
        ll mid_ = (ok_ + ng_) /2;
        if (D(mid_)) ok_ = mid_;
        else ng_ = mid_;
    }
    return ok_;
}

int main() {
    cin >> n;
    vector<ll> h(n);
    vector<ll> s(n);
    rep(i, n) cin >> h[i] >> s[i];

    ll res = LLONG_MAX;
    rep (i, n) {
        ll ok = 0, ng = LLONG_MAX;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (C(mid, h, s)) ok = mid;
            else ng = mid;
        }
        res = min(res, ok);
    }

    cout << res << endl;
}