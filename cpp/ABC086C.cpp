#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int t0 = 0, x0 = 0, y0 = 0;
    int can = 1;
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t - t0 < abs(x - x0) + abs(y - y0)) can = 0;
        else if ((t - t0 - abs(x - x0) - abs(y - y0)) % 2 != 0) can = 0;
        t0 = t;
        x0 = x;
        y0 = y;
    }

    if (can == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}