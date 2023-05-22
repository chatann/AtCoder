#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    int divisor = 0;
    int ans = 0;
    if (N % 2 == 0) N--; 
    for (int i = 1; i <= N; i += 2) {
        for (int j = 1; j <= i; j += 2) {
            if (i % j == 0) divisor++;
        }
        if (divisor == 8) ans++;
        divisor = 0;
    }
    cout << ans << endl;
}