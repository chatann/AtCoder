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
  string a, b;
  cin >> a >> b;
  istringstream str2int = istringstream(a+b);
  int num;
  str2int >> num;
  string ans = "No";
  rep(i, num + 1) {
    if (i * i == num) {
      ans = "Yes";
    }
  }
  cout << ans << endl;
}