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

int H, W;
string grid[2004];
int dp[2005][2005];
vector<P> jump[27];
int gi, gj, si, sj;
int used[27];

int main() {
  cin >> H >> W;
  rep(i, H) rep(j, W) dp[i][j] = INF;
  rep(i, H) cin >> grid[i];
  rep(i, H) rep(j, W) {
    int c = grid[i][j] - 'a';
    if (grid[i][j] == 'S') {
      si = i;
      sj = j;
    }
    if (grid[i][j] == 'G') {
      gi = i;
      gj = j;
    }
    if (c < 26 && c >= 0) {
      jump[c].emplace_back(i, j);
    }
  }
  queue<P> q;
  q.emplace(si, sj);
  dp[si][sj] = 0;
  while (q.size()) {
    auto [i, j] = q.front();
    if (grid[i][j] == 'G')
      break;
    q.pop();
    int c = grid[i][j] - 'a';
    if (c < 26 && c >= 0) {
      for (auto p : jump[c]) {
        if (used[c])
          break;
        ll ni = p.fi;
        ll nj = p.se;
        if (chmin(dp[ni][nj], dp[i][j] + 1))
          q.emplace(ni, nj);
      }
      used[c] = 1;
    }
    rep(k, 4) {
      int ni = i + dy[k];
      int nj = j + dx[k];
      if (ni >= H || ni < 0 || nj >= W || nj < 0)
        continue;
      if (grid[ni][nj] == '#')
        continue;
      if (chmin(dp[ni][nj], dp[i][j] + 1))
        q.emplace(ni, nj);
    }
  }
  int ans = dp[gi][gj];
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
  return 0;
}
