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

int H, W, K;
ll dp[5005][5005];
char grid[5005][5005];
int mod = 998244353;
int main() {
  cin >> H >> W >> K;
  rep(i, K) {
    int h, w;
    char c;
    cin >> h >> w >> c;
    h--;
    w--;
    grid[h][w] = c;
  }
  dp[0][0] = 1;
  rep(i, H) {
    rep(j, W) {
      if (grid[i][j] == 'X') {
        (dp[i + 1][j] += dp[i][j]) %= mod;
        (dp[i][j + 1] += dp[i][j]) %= mod;
      } else if (grid[i][j] == 'R') {
        (dp[i][j + 1] += dp[i][j]) %= mod;
      } else if (grid[i][j] == 'D') {
        (dp[i + 1][j] += dp[i][j]) %= mod;
      } else {
        //(dp[i][j] *= 2) %= mod;
        (dp[i + 1][j] += dp[i][j] * 2) %= mod;
        (dp[i][j + 1] += dp[i][j] * 2) %= mod;
        //
        (dp[i][j + 1] += dp[i][j]) %= mod;
        //
        (dp[i + 1][j] += dp[i][j]) %= mod;
      }
    }
  }
  ll ans = dp[H - 1][W - 1];
  rep(i, H * W - K)(ans *= 3) %= mod;
  cout << ans << endl;
  cout << dp[H - 1][W - 1] << endl;
  rep(i, H) {
    rep(j, W) { cout << dp[i][j] << " "; }
    cout << endl;
  }
  return 0;
}
