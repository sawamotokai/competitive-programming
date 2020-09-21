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

ll dp[200005];
ll dpsum[200005];
int mod = 998244353;
int main() {
  int N, K;
  cin >> N >> K;
  vi L(N), R(N);
  rep(i, K) cin >> L[i] >> R[i];
  dp[1] = 1;
  dpsum[1] = dp[1];
  rep2(i, 2, N) {
    rep(j, K) {
      int l = i - R[j];
      int r = i - L[j];
      if (r < 0)
        continue;
      chmax(l, 1);
      (dp[i] += dpsum[r] - dpsum[l - 1]) %= mod;
      if (dp[i] < 0)
        dp[i] += mod;
    }
    dpsum[i] = (dpsum[i - 1] + dp[i]) % mod;
    if (dpsum[i] < 0)
      dpsum[i] += mod;
  }
  cout << dp[N] << endl;
  return 0;
}
