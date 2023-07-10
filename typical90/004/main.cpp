#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int h, w;
vector<vector<int> > a;
vector<int> row(2010), column(2010);
int main() {
  cin >> h >> w;
  a.assign(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) {
    row[i] += a[i][j];
    column[j] += a[i][j];
  }
  rep(i, h) rep(j, w) {
    int b_ij = row[i] + column[j] - a[i][j];
    cout << b_ij;
    if (j != w-1) cout << " ";
    else cout << endl;
  }
}