#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int n;
string s;
int ans = 0;

int main() {
  cin >> n;
  cin >> s;

  reps(i, 1, n-2) {
    int cnt = 0;
    string x = s.substr(0, i);
    string y = s.substr(i);
    char alp;
    for (alp='a'; alp<='z'; ++alp) {
      if (x.find(alp)<1000 && y.find(alp)<1000) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;
}