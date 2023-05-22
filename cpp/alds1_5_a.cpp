#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    int q;
    cin >> q;
    vector<int> m(q);
    rep (i, q) {
        cin >> m[i];
    }

    vector<int> can(q);
    for (int bit = 0; bit < (1<<n); bit++) {
        int num = 0;
        rep (i, n) {
            if (bit & (1<<i)) num += A[i];
        }
        rep (i, q) {
            if (num == m[i]) can[i] = 1;
        }
    }

    rep (i, q) {
        if (can[i]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}