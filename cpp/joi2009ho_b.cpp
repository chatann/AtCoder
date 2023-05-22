#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> store(n + 1, 0);
    reps(i, 1, n) cin >> store[i];
    store[n] = d;
    sort(all(store));

    ll res = 0;
    rep(i, m) {
        ll order;
        cin >> order;
        int it = lower_bound(all(store), order) - store.begin();
        ll temp = abs(store[it] - order);
        if (it > 0) temp = min(order - store[it - 1], temp);
        res += temp;
    }

    cout << res << endl;
}