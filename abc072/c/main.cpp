#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int n;
int cnt[100010];
int ans = 0;

int main() {
  cin >> n;
  rep(i, n) {
    int m;
    cin >> m;
    cnt[m]++;
    if (m > 0) cnt[m-1]++;
    cnt[m+1]++;
  }

  rep(i, 100010) ans = max(ans, cnt[i]);

  cout << ans << endl;
}