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
ll L[100006];
ll R[100006];
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
    r--;
  }
  rep2(i, 1, l) { L[i] += L[i - 1] + abs(X[l - i]); }
  rep2(i, 1, r) { R[i] += R[i - 1] + X[rBegin + i - 1]; }
  // if I have a candle at the origin no cost entails
  ll ans = LINF;

  // use i items on theleft
  if (hasZero)
    K--;
  rep(i, l + 1) {
    ll now = 0;
    now += L[i] + R[K - i];
    cout << now << endl;
    chmin(ans, now);
  }
  cout << ans << endl;
  rep(i, l + 1) printf("%lld%c", L[i], i == l ? '\n' : ' ');
  rep(i, r + 1) printf("%lld%c", R[i], i == r ? '\n' : ' ');
  return 0;
}
