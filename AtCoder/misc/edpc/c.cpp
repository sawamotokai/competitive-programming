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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
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

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> D(n);
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    D[i] = make_tuple(a, b, c);
  }
  vector<vll> dp(n, vll(3, 0));
  dp[0][0] = get<0>(D[0]);
  dp[0][1] = get<1>(D[0]);
  dp[0][2] = get<2>(D[0]);
  rep2(i, 1, n - 1) {
    rep(j, 3) {
      if (j == 0) {
        chmax(dp[i][j], dp[i - 1][1] + get<0>(D[i]));
        chmax(dp[i][j], dp[i - 1][2] + get<0>(D[i]));
      }
      if (j == 1) {
        chmax(dp[i][j], dp[i - 1][0] + get<1>(D[i]));
        chmax(dp[i][j], dp[i - 1][2] + get<1>(D[i]));
      }
      if (j == 2) {
        chmax(dp[i][j], dp[i - 1][0] + get<2>(D[i]));
        chmax(dp[i][j], dp[i - 1][1] + get<2>(D[i]));
      }
    }
  }
  ll ans = 0;
  rep(i, 3) chmax(ans, dp[n - 1][i]);
  cout << ans << endl;
  return 0;
}
