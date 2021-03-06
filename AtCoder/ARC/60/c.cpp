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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
using vP = vector<P>;
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

ll dp[52][52][2555];
// dp[i][j][k] := # of cases; seen i cards, used j cards, sum is k
int main() {
  int n;
  cin >> n;
  int a;
  cin >> a;
  vi x(n);
  rep(I, n) cin >> x[I];
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, n + 1) {
      rep(k, 2505) {
        dp[i + 1][j][k] += dp[i][j][k];
        if (k - x[i] >= 0 and j) {
          dp[i + 1][j][k] += dp[i][j - 1][k - x[i]];
        }
      }
    }
  }
  ll ans = 0;
  rep(i, n + 1) {
    rep(j, 2505) {
      if (j == i * a)
        ans += dp[n][i][j];
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
