#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> vec;
    for (int i = 1; i <= max(A, B); i++) {
        if (A % i == 0 && B % i == 0) vec.push_back(i);
    }
    cout << vec[vec.size() - K] << endl;
}