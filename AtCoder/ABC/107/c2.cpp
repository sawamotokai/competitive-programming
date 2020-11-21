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
ll X[100005];
int main() {
  cin >> N >> K;
  bool hasZero = false;
  rep(i, N) {
    cin >> X[i];
    if (X[i] == 0)
      hasZero = true;
  }
  int l = N;
  rep(i, N) {
    if (X[i] >= 0) {
      l = i;
      break;
    }
  }
  int rBegin = l;
  int r = N - l;
  if (hasZero) {
    rBegin++;
    if (rBegin == N)
      rBegin--;
    r--;
  }
  // if I have a candle at the origin no cost entails
  ll ans = LINF;

  // use i items on theleft
  if (hasZero)
    K--;
  rep(i, N) X[i] = abs(X[i]);
  rep(i, l + 1) {
    if (r < (K - i))
      continue;
    ll now = 0;
    if (i >= K) {
      now = X[l - i];
      chmin(ans, now);
      continue;
    }
    if (i == 0) {
      assert(rBegin + K - 1 < N);
      now = X[rBegin + K - 1];
      chmin(ans, now);
      continue;
    }
    if (i == l && l == K) {
      now = X[0];
      chmin(ans, now);
      continue;
    }
    assert(rBegin + (K - i - 1) < N);
    if (X[l - i] < X[rBegin + (K - i - 1)]) {
      now = X[rBegin + (K - i - 1)] + 2 * X[l - i];
    } else {
      now = X[l - i] + 2 * X[rBegin + (K - i) - 1];
    }
    chmin(ans, now);
  }
  cout << ans << endl;
  return 0;
}
