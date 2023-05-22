#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep (i, n) {
        cin >> a[i];
    }
    vector< vector<int> > edge(n, vector<int>(n));
    rep (i, m) {
        int x, y;
        cin >> x >> y;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }
    
}