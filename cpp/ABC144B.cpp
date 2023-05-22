#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (i * j == N) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
}