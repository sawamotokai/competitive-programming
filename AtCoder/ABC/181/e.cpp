#include <algorithm>
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

ll L[200005];
ll R[200005];

int main() {
  int N, M;
  cin >> N >> M;
  vll H(N), W(M + 1);
  W[0] = -LINF;
  W[M] = LINF;
  rep(i, N) cin >> H[i];
  rep(i, M) cin >> W[i + 1];
  sort(all(H));
  rep2(i, 2, N - 1) {
    if (i & 1)
      continue;
    L[i] = L[i - 2] + H[i - 1] - H[i - 2];
  }
  rep3(i, N - 3, 0) {
    if (i & 1)
      continue;
    R[i] = R[i + 2] + H[i + 2] - H[i + 1];
  }
  ll ans = LINF;
  sort(all(W));
  rep(i, N) {
    if (i & 1)
      continue;
    ll child = H[i];
    ll now = L[i] + R[i];
    auto it = lower_bound(all(W), child);
    ll c = abs(child - *it);
    chmin(c, abs(child - *(it + 1)));
    now += c;
    chmin(ans, now);
  }
  cout << ans << endl;
  // rep(i, N) printf("%lld%c", R[i], i == N - 1 ? '\n' : ' ');
  // rep(i, N) printf("%lld%c", L[i], i == N - 1 ? '\n' : ' ');
  return 0;
}
