#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int a, b, c;

int main() {
  cin >> a >> b >> c;

  for (int i = 1; i <= b; i++) {
    if (a * i % b == c) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}