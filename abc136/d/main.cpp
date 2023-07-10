#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

string s;
int n;
int dp[33][100010];
int ans[100010];

int main() {
  cin >> s;
  n = s.length();
  rep(i, n) {
    if (s[i]=='R') {
      dp[0][i] = i + 1;
    } else {
      dp[0][i] = i - 1;
    }
  }

  rep(i, 32) {
    rep(j, n) {
      dp[i+1][j] = dp[i][dp[i][j]];
    }
  }

  rep(i, n) ans[dp[32][i]]++;
  rep(i, n-1) cout << ans[i] << " ";
  cout << ans[n-1] << endl;
}