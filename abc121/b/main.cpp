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
  ll n, m, c;
  cin >> n >> m >> c;
  vector<ll> b(m);
  rep(i, m) cin >> b[i];
  vector<vector<ll> > a(n, vector<ll>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> a[i][j];
    }
  }
  ll ans = 0;
  ll sum = 0;
  rep(i, n) {
    rep(j, m) {
      sum += a[i][j] * b[j];
    }
    sum += c;
    if (sum > 0) {
      ans++;
    }
    sum = 0;
  }
  cout << ans << endl;
}