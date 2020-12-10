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

int a, b, c;
double dp[104][104][104];

int main() {
  cin >> a >> b >> c;
  double ans = 0;
  int sum = a + b + c;
  // ans += a / (double)sum * (100 - a);
  // ans += b / (double)sum * (100 - b);
  // ans += c / (double)sum * (100 - c);
  memset(dp, -1, sizeof(dp));
  dp[a][b][c] = 0;
  rep2(i, a, 100) {
    rep2(j, b, 100) {
      rep2(k, c, 100) {
        dp[i + 1][j][k] += dp[i][j][k] + i / (double)(i + j + k) / 3;
        dp[i][j + 1][k] += dp[i][j][k] + j / (double)(i + j + k) / 3;
        dp[i][j][k + 1] += dp[i][j][k] + k / (double)(i + j + k) / 3;
      }
    }
  }
  rep(i, 101) {
    rep(j, 101) {
      ans += dp[100][i][j];
      ans += dp[i][100][j];
      ans += dp[i][j][100];
    }
  }
  cout << dp[100][100][100] << endl;
  return 0;
}
