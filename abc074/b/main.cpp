#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  rep(i, n) {
    ll x;
    cin >> x;
    ll a_dist = 2 * x;
    ll b_dist = 2 * abs(k - x);
    ans += min(a_dist, b_dist);
  }
  cout << ans << endl;
}