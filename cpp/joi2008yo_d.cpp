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

int main() {
    int m;
    cin >> m;
    vector<pint> zodiac(m);
    rep (i, m) {
        cin >> zodiac[i].first >> zodiac[i].second;
    }
    int n;
    cin >> n;
    vector<pint> pic(n);
    rep (i, n) {
        cin >> pic[i].first >> pic[i].second;
    }

    int ansx = 0, ansy = 0;
    rep (i, n) {
        int dx = pic[i].first - zodiac[0].first;
        int dy = pic[i].second - zodiac[0].second;
        vector<pint> zodiac2(n);
        rep (j, m) {
            zodiac2[j].first = zodiac[j].first + dx;
            zodiac2[j].second = zodiac[j].second + dy;
        }
        int match = 0;
        rep (i, m) {
            rep (j, n) {
                if (zodiac2[i].first == pic[j].first && zodiac2[i].second == pic[j].second) {
                    match++;
                    break;
                }
            }
        }
        if (match == m) {
            ansx = dx;
            ansy = dy;
        }
    }
    cout << ansx << " " << ansy << endl;
}