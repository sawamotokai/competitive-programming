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
int dx[] = {0, 1};
int dy[] = {-1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int H, W;
int dp[105][105][55];
int main() {
  cin >> W >> H;
  string s;
  cin >> s;
  int K = s.size();
  vvi grid(H, vi(W));
  rep(i, H) {
    string s;
    cin >> s;
    rep(j, W) { grid[i][j] = s[j] - '0'; }
  }
  // rep(i, H) {
  // rep(j, W) cout << grid[i][j];
  // cout << endl;
  // }
  rep3(i, H - 1, 0) {
    rep(j, W) {
      rep(k, K + 1) { dp[i][j][k] = INF; }
    }
  }
  dp[H - 1][0][0] = grid[H - 1][0];
  rep3(i, H - 1, 0) {
    rep(j, W) {
      rep(k, K + 1) {
        if (dp[i][j][k] == INF)
          break;
        int step;
        if (k < K)
          step = s[k] - '0';
        else
          step = 0;
        rep(l, 2) {
          // jump
          int ni = i + dy[l];
          int nj = j + dx[l];
          if (!(ni < 0 || ni >= H || nj < 0 || nj >= W)) {
            chmin(dp[ni][nj][k], dp[i][j][k] + grid[ni][nj]);
          }
          if (k == K)
            continue;
          // no jump
          ni = i + dy[l];
          nj = j + dx[l];
          if (ni != i)
            ni -= step;
          if (nj != j)
            nj += step;
          if (!(ni < 0 || ni >= H || nj < 0 || nj >= W)) {
            chmin(dp[ni][nj][k + 1], dp[i][j][k] + grid[ni][nj]);
          }
        }
      }
    }
  }
  int ans = INF;
  rep(k, K + 1) { chmin(ans, dp[0][W - 1][k]); }
  cout << ans << endl;
  return 0;
}
