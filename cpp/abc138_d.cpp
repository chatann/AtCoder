#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using Graph = vector<vector<int> >;

vector<int> op;
vector<int> seen;
void dfs(Graph &G, int p, int x, vector<int> &counter) {
    seen[p] = true;
    counter[p] += x;
    for (auto v : G[p]) {
        if (seen[v]) continue;
        dfs(G, v, x + op[v], counter);
    }
}

int main() {
    int n, q; cin >> n >> q;
    Graph G(n);
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> counter(n);
    op.resize(n);
    seen.resize(n);
    rep(i, q) {
        int p, x; cin >> p >> x;
        p--;
        op[p] += x;
    }
    dfs(G, 0, op[0], counter);
    rep(i, n) {
        if (i < n - 1) cout << counter[i] << " ";
        else cout << counter[i] << endl;
    }
}