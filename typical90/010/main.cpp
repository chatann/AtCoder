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
  ll n;
  cin >> n;
  
  v<ll> score1(n), score2(n);
  rep(i, n) {
    ll c, p;
    cin >> c >> p;
    if (c == 1) {
      score1[i] = p;
    } else {
      score2[i] = p;
    }
    if (i > 0) {
      score1[i] += score1[i-1];
      score2[i] += score2[i-1];
    }
  }
  ll q;
  cin >> q;
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    l--; r--;
    ll a = score1[r] - (l > 0 ? score1[l-1] : 0);
    ll b = score2[r] - (l > 0 ? score2[l-1] : 0);
    cout << a << " " << b << endl;
    }

  return 0;
}