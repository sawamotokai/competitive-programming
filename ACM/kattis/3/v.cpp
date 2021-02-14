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

ll n, k;

ll f(vector<P> &p) {
  sort(p.rbegin(), p.rend());
  ll rest = 0;
  ll now = 0;
  for (auto pa : p) {
    ll use = min(rest, pa.se);
    pa.se -= use;
    rest -= use;
    assert(rest >= 0);
    assert(pa.se >= 0);
    ll x = (pa.se - 1) / k + 1;
    if (pa.se <= 0)
      x = 0;
    rest += (((k - pa.se) % k) + k) % k;
    now += pa.fi * 2 * x;
  }
  return now;
}

int main() {
  cin >> n >> k;
  vector<P> p(n);
  rep(i, n) cin >> p[i].fi >> p[i].se;
  vector<P> le, ri;
  rep(i, n) {
    if (p[i].fi < 0) {
      le.eb(-p[i].fi, p[i].se);
    }
    if (p[i].fi > 0)
      ri.pb(p[i]);
  }
  ll ans = 0;
  ans += f(ri);
  ans += f(le);
  printf("%lld\n", ans);
  return 0;
}
