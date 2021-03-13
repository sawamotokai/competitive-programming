#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nl '\n'
#define endl '\n'
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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using P = pair<ll, ll>;
using gt = greater<P>;
using minq = priority_queue<P, vector<P>, gt>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
template <class T> void print(const initializer_list<T> &il) {
  for (auto x : il) {
    cout << x << " ";
  }
  cout << "\n";
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++
int dp[1005][2][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  rep(i, 1005) rep(j, 2) rep(k, 2) dp[i][j][k] = -INF;
  int n;
  cin >> n;
  vi s(n);
  rep(i, n) cin >> s[i];
  dp[0][0][0] = 0;
  rep(i, n) {
    chmax(dp[i + 1][1][0], dp[i][0][0] - s[i]);
    chmax(dp[i + 1][0][1], dp[i][1][0] + s[i]);
    chmax(dp[i + 1][1][0], dp[i][1][0]);
    chmax(dp[i + 1][0][0], dp[i][0][0]);
    chmax(dp[i + 1][0][0], dp[i][0][1]);
  }
  int ans = dp[n][1][0] + s[n - 1];
  chmax(ans, dp[n][1][1] + s[n - 1]);
  chmax(ans, dp[n][0][0]);
  chmax(ans, dp[n][0][1]);
  cout << ans << nl;
  // rep(i, n) print({dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]});
  return 0;
}
