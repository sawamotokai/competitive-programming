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

int N, K;
int main() {
  cin >> N >> K;
  vi A(N);
  rep(i, N) cin >> A[i];
  vvi dp(N + 1);
  int ans = 1;
  // dp[0].pb(A[0]);
  // rep2(i,1,N) {
  rep(i, N) {
    for (auto a : dp[ans - 1]) {
      if (abs(A[i] - a) <= K) {
        dp[ans].pb(A[i]);
      }
    }
    if (dp[ans].size())
      ans++;
    dp[0].pb(A[i]);
  }
  cout << ans << endl;
  return 0;
}
