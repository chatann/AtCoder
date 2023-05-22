#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    int P = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        P += X[i];
    }
    P /= N;
    int O = P - 1;
    int Q = P + 1;

    int powerO = 0, powerP = 0, powerQ = 0;
    for (int i = 0; i < N; i++) {
        powerO += pow(X[i] - O, 2);
        powerP += pow(X[i] - P, 2);
        powerQ += pow(X[i] - Q, 2);
    }

    cout << min({powerO, powerP, powerQ}) << endl;
}