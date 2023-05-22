#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;

int main() {
    int A, B;
    cin >> A >> B;
    int i = 0;
    int min = 0;
    while(((A - 1) * i + 1) < B) {
        ++i;
    }
    cout << i << endl;
}