#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int> >;

void dfs(const Graph &G, vector<bool> &seen, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, seen, next_v);
    }
}

vector<int> bfs(const Graph &G, vector<int> &dist) {
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto next_v : G[v]) {
            if (dist[next_v] != -1) continue;
            dist[next_v] = dist[next_v] + 1;
            que.push(next_v);
        }
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // vector<int> seen(N, false);
    // int res = 0;
    // for (int v = 0; v < N; ++v) {
    //     if (seen[v]) continue;
    //     dfs(G, seen, v);
    //     ++res;
    // }
    // cout << res << endl;

    vector<int> dist(N, -1);
    vector<int> res = bfs(G, dist);
    for (int i = 0; i < N; ++i) {
        cout << i << ": " << res[i] << endl;
    }
}