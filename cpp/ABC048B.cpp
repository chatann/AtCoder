#include <bits/stdc++.h>
using namespace std;

int main() {
    long a, b, x;
    cin >> a >> b >> x;
    if (a % x != 0) a += x - a % x;
    if (a > b) cout << 0 << endl;
    else cout << (b - a) / x + 1 << endl;
}

/*int f(int n, int x) {
    if (n >= 0) return n / x + 1;
    else return 0;
}

int main() {
    long a, b, x;
    cin >> a >> b >> x;
    cout << f(b, x) - f(a - 1, x) << endl;
}*/