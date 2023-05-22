#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a ,n) for (int i = (a); i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    rep (i, 1000) {
        int num[3];
        num[0] = i / 100;
        num[1] = i / 10 % 10;
        num[2] = i % 10;
        int cur = 0;
        rep (j, N) {
            if (num[cur] == S[j] - '0') cur++;
            if (cur == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}