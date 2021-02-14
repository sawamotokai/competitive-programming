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

int n, m;
string grid[55];
ll dp[55][55][55];
struct Data {
  int x, y;
  int idx;
  Data(int y, int x, int idx) : y(y), x(x), idx(idx){};
};
// dp[i][j][k] := at kth letter, at (i, j)s square
int main() {
  cin >> n >> m;
  rep(i, n) cin >> grid[i];
  string s;
  cin >> s;
  int l = s.size();
  rep(i, n + 1) rep(j, m + 1) rep(k, l + 1) dp[i][j][k] = INF;
  int sy, sx, gx, gy;
  rep(i, n) rep(j, m) {
    if (grid[i][j] == 'R')
      sy = i, sx = j;
    if (grid[i][j] == 'E')
      gy = i, gx = j;
  }
  dp[sy][sx][0] = 0;
  deque<Data> q;
  q.emplace_back(sy, sx, 0);
  while (q.size()) {
    int i = q.front().y;
    int j = q.front().x;
    int k = q.front().idx;
    if (i == gy and j == gx) {
      cout << dp[i][j][k] << endl;
      return 0;
    }
    q.pop_front();
    // cout << i << " " << j << " " << k << endl;
    // move
    int ni = -1;
    int nj = -1;
    if (s[k] == 'R') {
      ni = i;
      nj = j + 1;
    }
    if (s[k] == 'L') {
      ni = i;
      nj = j - 1;
    }
    if (s[k] == 'U') {
      ni = i - 1;
      nj = j;
    }
    if (s[k] == 'D') {
      ni = i + 1;
      nj = j;
    }
    if (ni < 0 or nj < 0 or ni >= n or nj >= m or grid[ni][nj] == '#') {
      ni = i;
      nj = j;
    }
    if (chmin(dp[ni][nj][k + 1], dp[i][j][k])) {
      q.emplace_front(ni, nj, k + 1);
    }
    // delete
    if (k < l && chmin(dp[i][j][k + 1], dp[i][j][k] + 1)) {
      q.emplace_back(i, j, k + 1);
      // puts("2");
    }
    rep(z, 4) {
      ni = i + dy[z];
      nj = j + dx[z];
      if (ni < 0 or nj < 0 or ni >= n or nj >= m or grid[ni][nj] == '#')
        continue;
      if (chmin(dp[ni][nj][k], dp[i][j][k] + 1)) {
        q.emplace_back(ni, nj, k + 1);
      }
    }
  }
  ll ans = INF;
  rep(i, l + 1) chmin(ans, dp[gy][gx][i]);
  cout << ans << endl;
  return 0;
}
