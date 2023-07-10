#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int n;
int a[110];
int max = 0, min = 4800;
int color[8];

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];

  int fre = 0;
  rep(i, n) {
    if (a[i] < 400) color[0] = 1;
    else if (a[i] < 800) color[1] = 1;
    else if (a[i] < 1200) color[2] = 1;
    else if (a[i] < 1600) color[3] = 1;
    else if (a[i] < 2000) color[4] = 1;
    else if (a[i] < 2400) color[5] = 1;
    else if (a[i] < 2800) color[6] = 1;
    else if (a[i] < 3200) color[7] = 1;
    else fre++;
  }

  int ans = 0;
  rep(i, 8) if (color[i]) ans++;
  if (ans > 0) cout << ans << " " << ans + fre << endl;
  else cout << "1 " << fre << endl;
}