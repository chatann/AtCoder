#include <bits/stdc++.h>
using namespace std;

int main() {
    double p;
    cin >> p;

    double logp = log(p);
    double x_0 = logp - log(1.5/log(2.0));
    double res = 1.5/log(2.0) * (logp + 1.0 - log(1.5/log(2.0)));
    cout << fixed << setprecision(10);
    if (x_0 >=0) cout << res << endl;
    else cout << p << endl;
}