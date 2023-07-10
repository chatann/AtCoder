#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int n, k, l;
int a[1 << 18];

int solve(int m) {
  int cnt = 0, pre = 0;
  rep(i, n) {
    if ((a[i] - pre >= m) && (l - a[i] >= m)) {
      cnt++;
      pre = a[i];
    }
  }
  if (cnt >= k) return true;
  else return false;
}

int main() {
  cin >> n >> l;
  cin >> k;
  rep(i, n) cin >> a[i];

  int left = -1, right = l + 1;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (solve(mid)) left = mid;
    else right = mid;
  }
  cout << left << endl;
}