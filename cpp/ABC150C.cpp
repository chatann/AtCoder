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
    vector<int> p(n);
    vector<int> q(n);
    rep (i, n) {cin >> p[i];}
    rep (i, n) {cin >> q[i];}

    vector<int> order(n);
    rep (i, n) {order[i] = i + 1;}

    int ans = 0;
    int num = 0, a = 0, b = 0;
    int ok_a = 0, ok_b = 0;
    do {
        int canp = 1, canq = 1;
        rep (i, n) {
            if (order[i] != p[i]) canp = 0;
            if (order[i] != q[i]) canq = 0;
        }
        if (canp) {
            a = num;
            ok_a = 1;
        }
        if (canq) {
            b = num;
            ok_b = 1;
        }
        if (ok_a && ok_b) {
            ans = abs(a - b);
            break;
        }
        num++;
    } while (next_permutation(all(order)));

    cout << ans << endl;
}