#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using Graph = vector< vector<int> >;

vector<bool> seen;
vector<int> d;
vector<int> f;
void dfs(const Graph &G, int v, int& time) {
    d[v] = ++time;
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v, time);
    }
    f[v] = ++time;
}

int main() {
    int n; cin >> n;
    Graph G(n);
    rep(i, n) {
        int u, k; cin >> u >> k;
        u--;
        G[u].resize(k);
        rep(j, k) {
            int v; cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    
    seen.assign(n, false);
    d.resize(n);
    f.resize(n);
    int time = 0;
    rep(v, n) {
        if (!seen[v]) dfs(G, v, time);
    }
    rep(v, n) {
        cout << v + 1 << " " << d[v] << " " << f[v] << endl;
    }
}