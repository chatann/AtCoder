#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

ll sum_k(ll m) {
  ll sum = 0;
  rep(i, m) {
    sum += i;
  }
  return sum;
}

int main() {
  ll n;
  cin >> n; 
  cout << sum_k(n) << endl;
}