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

ll bfs(v<v<ll> >& g, ll s){
  ll n = len(g);
  v<ll> dist(n, -1);
  queue<ll> q;
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    ll v = q.front();
    q.pop();
    for (auto u: g[v]) {
      if (dist[u] != -1) continue;
      dist[u] = dist[v] + 1;
      q.push(u);
    }
  }
  so(dist);
  return dist[n-1];
}

int main(){
  ll n1, n2, m;
  cin >> n1 >> n2 >> m;
  v<v<ll> > g1(n1), g2(n2);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    if (a <= n1) {
      a--; b--;
      g1[a].push_back(b);
      g1[b].push_back(a);
    } else {
      a = n1 + n2 - a;
      b = n1 + n2 - b;
      g2[a].push_back(b);
      g2[b].push_back(a);
    }
  }

  ll dist1 = bfs(g1, 0);
  ll dist2 = bfs(g2, 0);
  ll ans = dist1 + dist2 + 1;
  p(ans);

  return 0;
}