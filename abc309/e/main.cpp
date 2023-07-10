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

v<ll> bfs(v<v<ll> >& g){
  ll n = len(g);
  v<ll> d(n, INF);
  queue<ll> q;
  q.push(0);
  d[0] = 0;
  while (!q.empty()) {
    ll v = q.front(); q.pop();
    for (auto u: g[v]) {
      if (d[u] != INF) continue;
      d[u] = d[v] + 1;
      q.push(u);
    }
  }
  return d;
}

int main(){
  ll n, m;
  cin >> n >> m;
  v<ll> p(n), x(m), y(m);
  rep(i, n-1) cin >> p[i];
  rep(i, m) cin >> x[i] >> y[i];

  v<v<ll> > g(n);
  rep(i, n-1){
    g[i+1].push_back(p[i]-1);
    g[p[i]-1].push_back(i+1);
  }
  v<ll> d = bfs(g);
  rep(i, n) cout << i << ": " << d[i] << endl;

  return 0;
}