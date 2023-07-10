#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

ll n, a, b;
string s;
int main() {
  cin >> n >> a >> b;
  cin >> s;
  ll cnt_a = 0, cnt_b = 0;
  rep(i, n) {
    if (s[i] == 'a') {
      if (cnt_a + cnt_b < a + b) {
        cout << "Yes" << endl;
        cnt_a++;
      } else {
        cout << "No" << endl;
      }
    } else if (s[i] == 'b') {
      if (cnt_a + cnt_b < a + b && cnt_b < b) {
        cout << "Yes" << endl;
        cnt_b++;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}