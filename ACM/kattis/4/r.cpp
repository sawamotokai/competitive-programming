#include <algorithm>
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
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  rep(i, n - 1) {
    if (s[i] > s[i + 1]) {
      cout << -1 << endl;
      return;
    }
  }
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(10, vll(2)));
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, 10) {
      rep(sm, 2) {
        if (sm) {
          rep2(nx, j, 9) dp[i + 1][nx][1] += dp[i][j][1];
        } else {
          int d = s[i] - '0';
          rep2(nx, j, d - 1) dp[i + 1][nx][1] += dp[i][j][0];
          dp[i + 1][d][0] += dp[i][j][0];
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 10) {
    rep(j, 2) { ans += dp[n][i][j]; }
  }
  cout << ans - 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
