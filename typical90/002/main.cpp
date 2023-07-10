#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int n;

vector<string> row(int l) {
  vector<string> ans;
  if (l == 0) {
    ans.push_back("()");
    return ans;
  }
  vector<string> pre = row(l - 2);
  for (const string& s : pre) {
    ans.push_back("(" + s + ")");
    ans.push_back("()" + s);
    ans.push_back(s + "()");
  }
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  return ans;
}

int main() {
  cin >> n;
  if (n % 2 != 0) {
    cout << endl;
    return 0;
  } else {
    vector<string> ans = row(n - 2);
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) cout << ans[i] << endl;
  }
}