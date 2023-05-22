#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

ll GetDigit(ll num) {
    ll digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}

ll F(ll A, ll B) {
    return GetDigit(max(A, B));
}

int main() {
    ll N;
    cin >> N;
    vector<ll> vec;
    for (ll A = 1; A * A <= N; A++) {
        if (N % A == 0) vec.push_back(F(A, N/A));
    }
    cout << *min_element(vec.begin(), vec.end()) << endl;
}