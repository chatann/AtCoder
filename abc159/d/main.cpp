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

//p(出力) d(デバッグ *多次元配列も可能*)
#define p(x) cout << x << endl;
#define d(x) dbgn(#x, x);

const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7

int main(){
  ll n;
  v<ll> a(1000100), num(1000100);
  cin >> n;
  rep(i, n) {
    cin >> a[i];
    num[a[i]]++;
  }

  ll sum = 0;
  repp(i, 1, n+1) {
      ll m = num[i];
      sum += m * (m - 1) / 2;
  }

  rep(k, n) {
    if (num[a[k]] > 0) cout << sum - (num[a[k]] - 1) << endl;
    else cout << sum << endl;
  }
  return 0;
}