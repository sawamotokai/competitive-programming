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

ll N, W;
ll tl[200005];

int main() {
  cin >> N >> W;
  vll S(N);
  vll T(N);
  vll P(N);
  rep(i, N) cin >> S[i] >> T[i] >> P[i];
  rep(i, N) {
    tl[S[i]] += P[i];
    tl[T[i]] -= P[i];
  }
  bool ok = true;
  rep(i, 200004) { tl[i + 1] += tl[i]; }
  rep(i, 200004) if (tl[i] > W) ok = false;
  // rep(i, 14) printf("%lld%c", tl[i], i == 13 ? '\n' : ' ');
  ok();
  return 0;
}
