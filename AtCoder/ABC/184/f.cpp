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

int n, t;
int main() {
  cin >> n >> t;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> b;
  vector<ll> c;
  int m = n / 2;
  int r = n - m;
  rep(i, 1 << m) {
    ll sum = 0;
    rep(j, m) {
      if ((i >> j) & 1) {
        sum += a[j];
      }
    }
    b.pb(sum);
  }
  rep(i, 1 << r) {
    ll sum = 0;
    rep(j, r) {
      if ((i >> j) & 1) {
        sum += a[j + m];
      }
    }
    c.pb(sum);
  }
  sort(all(b));
  sort(all(c));
  ll ans = 0;
  for (ll num : b) {
    ll s = t - num;
    auto it = lower_bound(all(c), s);
    if (*it != s) {
      if (it != c.begin())
        it--;
      else
        continue;
    }
    chmax(ans, *it + num);
  }
  cout << ans << endl;
  return 0;
}
