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
  string s;
  cin >> s;
  ll n = s.size();
  for (int i = 0; i < n; i += 2) {
    string former = s.substr(0, (n-i)/2);
    string latter = s.substr((n-i)/2, (n-i)/2);
    if (former == latter) {
      if (i!=0) {
        cout << n-i << endl;
        break;
      }
    }
  }
}