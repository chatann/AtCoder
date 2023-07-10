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
  ll n, m;
  cin >> n >> m;
  ll a1, a2;
  v<ll> a(n-2);
  rep(i, n) {
    if (i == 0) cin >> a1;
    else if (i == 1) cin >> a2;
    else cin >> a[i-2];
  }
  so(a);

  ll ans = INF;
  if (m == 1) {
    if (a[0] < a1) ans = a1 - a[0];
    if (a[0] > a2) ans = min(ans, a[0] - a2);
    if (a[0] >= a1 && a[0] <= a2) ans = 0;
    p(ans);
    return 0;
  }

  rep(i, n-m-1) {
    ll tmp = 0;
    if (a[i] < a1 && a2 < a[i+m-1]) {
      tmp = abs(a[i] - a1 - (a[i+m-1] - a2));
    } else if (a[i] < a1) {
      tmp = a1 - a[i];
    } else if (a2 < a[i+m-1]) {
      tmp = a[i+m-1] - a2;
    }
    ans = min(ans, tmp);
  }
  p(ans);
  return 0;
}