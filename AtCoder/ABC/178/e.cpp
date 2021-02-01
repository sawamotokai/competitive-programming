#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

int main() {
  cin >> N;
  vector<P> p(N);
  rep(i, N) cin >> p[i].fi >> p[i].se;
  sort(all(p));
  vll S(N);
  vll D(N);
  rep(i, N) {
    S[i] = p[i].fi + p[i].se;
    D[i] = p[i].fi - p[i].se;
  }
  ll ans = 0;
  ll mx = -LINF;
  ll mn = LINF;
  rep(i, N) {
    chmax(mx, S[i]);
    chmin(mn, S[i]);
  }
  chmax(ans, mx - mn);
  mx = -LINF;
  mn = LINF;
  rep(i, N) {
    chmax(mx, D[i]);
    chmin(mn, D[i]);
  }
  chmax(ans, mx - mn);
  cout << ans << endl;
  return 0;
}
