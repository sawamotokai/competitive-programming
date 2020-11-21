#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
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

int H, W;
string grid[2005];
ll dp[2005][2005];

ll up[2005][2006];
ll le[2005][2006];
ll diag[2005][2006];

int mod = 1e9 + 7;

int main() {
  cin >> H >> W;
  rep(i, H) cin >> grid[i];
  dp[0][0] = 1;
  up[0][0] = 1;
  diag[0][0] = 1;
  le[0][0] = 1;
  ll sumU = 1;
  ll sumL = 1;
  ll sumD = 1;
  rep(i, H) {
    rep(j, W) {
      if (i == 0 && j == 0)
        continue;
      if (i)
        (dp[i][j] += (up[i - 1][j])) %= mod;
      if (j)
        (dp[i][j] += (le[i][j - 1])) %= mod;
      if (j && i)
        (dp[i][j] += (diag[i - 1][j - 1])) %= mod;

      if (i) {
        (up[i][j] += up[i - 1][j] + dp[i][j]) %= mod;
      }
      if (j) {
        (le[i][j] += le[i][j - 1] + dp[i][j]) %= mod;
      }
      if (j && i) {
        (diag[i][j] += diag[i - 1][j - 1] + dp[i][j]) %= mod;
      }
      if (i == 0) {
        up[0][j] = dp[0][j];
        diag[0][j] = dp[0][j];
      }
      if (j == 0) {
        le[i][0] = dp[i][0];
        diag[i][0] = dp[i][0];
      }
      if (grid[i][j] == '#') {
        up[i][j] = 0;
        le[i][j] = 0;
        diag[i][j] = 0;
      }
    }
  }
  ll ans = dp[H - 1][W - 1];
  cout << ans << endl;
  // rep(i, H) {
  //   rep(j, W) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  // puts("");
  // rep(i, H) {
  //   rep(j, W) { cout << up[i][j] << " "; }
  //   cout << endl;
  // }
  // puts("");
  // rep(i, H) {
  //   rep(j, W) { cout << le[i][j] << " "; }
  //   cout << endl;
  // }
  // puts("");
  // rep(i, H) {
  //   rep(j, W) { cout << diag[i][j] << " "; }
  //   cout << endl;
  // }
  // puts("");
  return 0;
}
