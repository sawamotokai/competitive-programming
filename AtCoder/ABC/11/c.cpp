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

int N;
int dp[305];
int main() {
  vi ng(3);
  cin >> N >> ng[0] >> ng[1] >> ng[2];
  bool ok = true;
  rep(i, 3) {
    if (ng[i] == N) {
      puts("NO");
      return 0;
    }
  }
  rep(i, N) dp[i] = -INF;
  dp[N] = 100;
  rep3(i, N, 0) {
    if (dp[N] == 0)
      continue;
    rep2(j, 1, 3) {
      if (i - j == ng[0] || i - j == ng[1] || i - j == ng[2])
        continue;
      if (i - j < 0)
        continue;
      chmax(dp[i - j], dp[i] - 1);
    }
  }
  if (dp[0] >= 0) {
    puts("YES");
  } else
    puts("NO");
  // rep(i, N + 1) cout << dp[i] << endl;
  return 0;
}
