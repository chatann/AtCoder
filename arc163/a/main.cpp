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
  ll t;
  cin >> t;
  rep(i, t) {
    ll n;
    string s;
    cin >> n;
    cin >> s;
    string ans = "No";
    reps(j, 1, n) {
      string first = s.substr(0, j);
      reps(k, 1, n) {
        string second = s.substr(j, k);
        if (first < second) {
          ans = "Yes";
        }
      }
    }
    cout << ans << endl;
  }
}