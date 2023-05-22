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
    int n;
    cin >> n;
    vector<pint> coor(n);
    rep (i, n) {
        cin >> coor[i].first >> coor[i].second;
    }
    vector< vector<double> > dist(n, vector<double>(n));
    rep (i, n) {
        rep (j, n) {
            dist[i][j] = sqrt(pow((coor[i].first - coor[j].first), 2) + pow((coor[i].second - coor[j].second), 2));
        }
    }
    vector<int> order(n);
    rep (i, n) {
        order[i] = i;
    }
    double path = 0;
    int path_num = 0;
    do {
        double temp_path = 0;
        rep (i, n - 1) {
            temp_path += dist[order[i]][order[i + 1]];
        }
        path += temp_path;
        path_num++;
    } while (next_permutation(all(order)));
    cout << fixed << setprecision(10);
    cout << path / path_num << endl;
}