#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int h, w;
vector<string> s(50);
vector<vector<int> > ans(50, vector<int>(50));

int main() {
  cin >> h >> w;
  rep(i, h) cin >> s[i];

  rep(i, h) rep(j, w) {
    if (s[i][j] != '#') continue;
    if (i > 0) {
      ans[i-1][j]++;
      if (j > 0) ans[i-1][j-1]++;
      if (j < w-1) ans[i-1][j+1]++;
    }
    if (i < h-1) {
      ans[i+1][j]++;
      if (j > 0) ans[i+1][j-1]++;
      if (j < w-1) ans[i+1][j+1]++;
    }
    if (j > 0) {
      ans[i][j-1]++;
    }
    if (j < w-1) {
      ans[i][j+1]++;
    }
  }

  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') cout << '#';
    else cout << ans[i][j];
    if (j == w-1) cout << endl;
  }
}