#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok ? "Yes" : "No");
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll, ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  vector<vector<int>> ans(h, vector<int>(w, 0));
  vi pendingUp;
  vi pendingDown;
  int color = 1;
  bool ok = false;
  rep(i, h) {
    int cnt = 0;
    rep(j, w) if (grid[i][j] == '#') cnt++;
    if (cnt == 0) {
      if (ok)
        pendingUp.push_back(i);
      else
        pendingDown.push_back(i);
      continue;
    }
    ok = true;
    if (cnt == 1) {
      ans[i] = vector<int>(w, color);
      color++;
      continue;
    }
    int t = 0;
    rep(j, w) {
      if (grid[i][j] == '#') {
        if (t)
          color++;
        t++;
      }
      ans[i][j] = color;
      if (j == w - 1)
        color++;
    }
  }
  for (int r : pendingUp)
    ans[r] = ans[r - 1];
  for (int i = pendingDown.size() - 1; i >= 0; i--)
    ans[pendingDown[i]] = ans[pendingDown[i] + 1];
  rep(i, h) {
    rep(j, w) { cout << ans[i][j] << " "; }
    cout << endl;
  }
  return 0;
}
