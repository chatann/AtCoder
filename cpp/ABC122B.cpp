#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    int count = 0;
    vector<int> vec(10);
    rep(i, S.size()) {
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
            count++;
        } else {
            vec.push_back(count);
            count = 0;
        }
    }
    vec.push_back(count);
    cout << *max_element(vec.begin(), vec.end()) << endl;
}