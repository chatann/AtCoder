#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

const ll INF_L = 1LL << 60;
const int INF_I = 1 << 30;

int main() {
  vector<vector<ll> > a(3, vector<ll>(3));
  rep(i, 3) {
    rep(j, 3) {
      cin >> a[i][j];
    }
  }
  ll n;
  cin >> n;

  vector<vector<ll> > card(3, vector<ll>(3));
  rep(i, n) {
    ll b;
    cin >> b;
    rep(k, 3) {
      rep(j, 3) {
        if (a[k][j] == b) {
          card[k][j] = 1;
        }
      }
    }
  }
  rep(i, 3) {
    if (card[i][0] == 1 && card[i][1] == 1&& card[i][2] == 1) {
      cout << "Yes" << endl;
      return 0;
    } else if (card[0][i] == 1 && card[1][i] == 1 && card[2][i] == 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (card[0][0] == 1 && card[1][1] == 1 && card[2][2] == 1) {
    cout << "Yes" << endl;
    return 0;
  } else if (card[0][2] == 1 && card[1][1] == 1 && card[2][0] == 1) {
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
    return 0;
  }
}