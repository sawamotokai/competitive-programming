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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

ll N;
ll dp[1 << 20][20];
ll costs[20][20];
ll coord[20][3]; // x,y,x

int main() {
  cin >> N;
  rep(i, 20) rep(j, 20) costs[i][j] = INF;
  rep(i, N) {
    int a, b, c;
    cin >> a >> b >> c;
    coord[i][0] = a;
    coord[i][1] = b;
    coord[i][2] = c;
  }
  rep(i, N) {
    rep(j, N) {
      costs[i][j] = abs(coord[i][0] - coord[j][0]) +
                    abs(coord[i][1] - coord[j][1]) +
                    max(0ll, coord[j][2] - coord[i][2]);
    }
  }
  rep(i, 1 << 20) rep(j, 20) dp[i][j] = LINF;
  rep(i, N) {
    if (i == 0)
      continue;
    dp[1 << i][i] = costs[0][i];
  }
  rep(bits, 1 << N) {
    rep(v, N) {
      rep(u, N) { chmin(dp[bits | (1 << v)][v], dp[bits][u] + costs[u][v]); }
    }
  }
  ll ans = dp[(1 << N) - 1][0];
  if (ans == LINF)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}
