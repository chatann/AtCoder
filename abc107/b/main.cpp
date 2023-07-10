#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;

template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T> >;
template<typename T> using vvv = vector<vector<vector<T> > >;
template<typename T> inline void errv(T& v) { for (auto x: v) cerr << x << " "; cerr << endl; }
inline void errv(vector<bool>& v) { for (auto x: v) cerr << (x ? 1 : 0) << " "; cerr << endl; }
template<typename T> inline void dbgn(string n, T x) { cerr << n << ": " << x << endl; }
template<typename T> inline void dbgn(string n, vector<T>& v) { cerr << n << ": "; errv(v); }
template<typename T> inline void dbgn(string n, vector<vector<T> >& m) { cerr << n << ":" << endl; for (auto& v: m) errv(v); }

#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
#define repa(i, a) for (auto i: a)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define so(v) sort((v).begin(), (v).end())
#define rso(v) sort((v).rbegin(), (v).rend())
#define len(x) ll((x).size())

const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7

int main(){
  int h, w;
  cin >> h >> w;
  vv<int> a(h, v<int>(w));
  rep(i, h) {
    string s;
    cin >> s;
    rep (j, w) {
      if (s[j] == '#') a[i][j] = 1;
      else a[i][j] = 0;
    }
  }

  v<int> row(h, 0), col(w, 0);
  rep(i, h) {
    if (count(all(a[i]), 1) == 0) {
      row[i] = 1;
    }
  }
  rep(j, w) {
    int can = true;
    rep(i, h) {
      if (a[i][j] == 1) can = false;
    }
    if (can) col[j] = 1;
  }
  
  rep(i, h) {
    rep(j, w) {
      if (row[i] == 0 && col[j] == 0) {
        if (a[i][j] == 1) cout << '#';
        else cout << '.';
      }
    if (row[i] == 0 && j == w-1) cout << endl;
    }
  }
  return 0;
}