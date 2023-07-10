#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

ll n;
int main() {
  cin >> n;
  rep(i, 50000) {
    if (floor(i * 1.08) == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}