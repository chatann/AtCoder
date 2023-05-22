#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int count = 0;
    rep(i, N - 2) {
        if (S[i] == 'A') {
            if (S[i+1] == 'B') {
                if (S[i+2] == 'C') {
                    count++;
                } else {
                    i++;
                }
            }
        }
    }
    cout << count << endl;
}