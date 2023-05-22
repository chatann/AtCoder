#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;


ll n, h, a, b, c, d, e;

int main() {
    cin >> n >> h;
    cin >> a >> b >> c >> d >> e;
    ll res = INF_L;
    rep(i, n + 1) {
        ll ng = -1, ok = n - i;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (h + b*i + d*mid - e*(n-i-mid) > 0) ok = mid;
            else ng = mid;
        }
        res = min(res, a*i + c*ok);
    }
    cout << res << endl;
}
