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
    vector< vector<int> > graph(n + 1, vector<int>(n + 1));
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    vector<int> order(n - 1);
    rep (i, n - 1) {order[i] = i + 2;}
    vector<int> first;
    rep (i, n - 1) {
        if (graph[1][order[i]]) first.push_back(order[i]);
    }

    int ans = 0;
    do {
        int can = 1;
        int can2 = 0;
        for (int i : first) {
            if (order[0] == i)  {
                can2 = 1;
                break;
            }
        }
        if (can2) {
            rep (i, n - 2) {
                if (!graph[order[i]][order[i + 1]]) {
                    can = 0;
                    break;
                }
            }
        }
        if (can && can2) ans++;
    } while(next_permutation(all(order)));

    cout << ans << endl;
}