#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    string divide[4] = {"dream", "dreamer", "erase", "eraser"};

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; i++) reverse(divide[i].begin(), divide[i].end());

    int can1 = 1;
    for (int i = 0; i < S.size();) {
        int can2 = 0;
        for (int j = 0; j < 4; j++) {
            string d = divide[j];
            if (S.substr(i, d.size()) == d) {
                can2 = 1;
                i += d.size();
            }
            
        }
        if (can2 == 0) {
            can1 = 0;
            break;
        }
    }

    if (can1) cout << "YES" << endl;
    else cout << "NO" << endl;

}