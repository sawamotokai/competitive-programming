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

int N;
ll A[200005];

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  vll SS(N + 1);
  vll dp(N + 1);
  ll ans = 0;
  ll maxPos = 0;
  rep2(i, 1, N) {
    // if (A[i - 1] >= 0)
    //   maxPos = i;
    SS[i] += SS[i - 1] + A[i - 1];
    if (SS[i] > SS[maxPos])
      maxPos = i;
    ll neg = SS[i] - SS[maxPos];
    ll nx = SS[i - 1] + dp[i - 1] + A[i - 1];
    ll cand = dp[i - 1] + SS[maxPos];
    // printf("cand:%d nx: %d neg%d SS[i]: %lld\n", cand, nx, neg, SS[i]);
    dp[i] = nx;
    chmax(ans, cand);
  }
  printf("%lld\n", ans);
  // rep(i, N + 1) printf("%lld%c", dp[i], i == N ? '\n' : ' ');
  // rep(i, N + 1) printf("%lld%c", SS[i], i == N ? '\n' : ' ');
  return 0;
}
