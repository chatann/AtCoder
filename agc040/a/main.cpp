#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

ll sum_k(ll n) {
  ll sum = 0;
  rep(i, n) {
    sum += i + 1;
  }
  return sum;
}

int main() {
  string s;
  cin >> s;
  ll ans = 0;
  ll start = 0;
  rep(i, s.size()) {
    if ((s[i]=='>' && s[i+1]=='<') || i == s.size()-1) {
      string tmp = s.substr(start, i+1-start);
      ll big_cnt = count(all(tmp), '>');
      ll small_cnt = count(all(tmp), '<');
      ans += sum_k(max(big_cnt, small_cnt)) + sum_k(min(big_cnt, small_cnt)-1);
      start = i + 1;
    }
  }
  cout << ans << endl;
}