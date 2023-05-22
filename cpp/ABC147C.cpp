#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<vector<pint> > honest(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        honest[i].resize(A);
        for (int j = 0; j < A; j++) {
            cin >> honest[i][j].first >> honest[i][j].second;
            --honest[i][j].first;
        }
    }

    int res = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        int can = 1;
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (!can) break;
            if (!(bit & (1<<i))) continue;
            for (pint xy : honest[i]) {
                int x = xy.first;
                int y = xy.second;
                if (y == 1 && !(bit & (1<<x))) {
                    can = 0;
                    break;
                }
                if (y == 0 && (bit & (1<<x))) {
                    can = 0;
                    break;
                }
            }
            ++count;
        }
        if (can) res = max(count, res);
    }

    cout << res << endl;
}