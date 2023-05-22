#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    int count = 0;
    rep(i, N + 1) {
        if (i >= 1 && i <= 9) count++;
        if (i >= 100 && i <= 999) count++;
        if (i >= 10000 && i <= 99999) count++;
    }
    cout << count << endl;
}