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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }
  ll ans = 0;
  ll light = 0;
  while (true) {
    ll next = a[light];
    if (next == -1) {
      cout << -1 << endl;
      break;
    }
    a[light] = -1;
    light = next;   
    ans++;
    if (light == 1) {
      cout << ans << endl;
      break;
    }
  }
}