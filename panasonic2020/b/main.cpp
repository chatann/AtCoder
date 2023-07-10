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
  ll h, w;
  cin >> h >> w;
  ll ans = 0;
  ll odd_row = (w + 1) / 2;
  ll even_row = w / 2;
  if (h % 2 == 0) {
    ans = (odd_row + even_row) * (h / 2);
  } else {
    ans = (odd_row + even_row) * (h / 2) + odd_row;
  }
  if (h == 1 || w == 1) {
    cout << 1 << endl;
    return 0;
  }
  cout << ans << endl;
}