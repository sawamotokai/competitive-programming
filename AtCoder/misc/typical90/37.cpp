#include <atcoder/all>
#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nl '\n'
#define endl '\n'
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
#define pcnt(x) __builtin_popcountll(x)
#define df(x) ll x = in();
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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using P = pair<ll, ll>;
using gt = greater<P>;
template <class T> using minq = priority_queue<T, vector<T>, greater<T>>;
using vP = vector<P>;
inline ll in() {
  ll x;
  scanf("%lld", &x);
  return x;
}
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
template <class T> void print(const initializer_list<T> &il) {
  for (auto x : il) {
    cout << x << " ";
  }
  cout << "\n";
}
inline void priv(vll a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
}
inline void priv(vi a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
}
const ll LINF = 8e18L + 1;
const int INF = 8e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// g++ -std=c++17 -stdlib=libc++
#define _GLIBCXX_DEBUG
// This slows down the execution; even the time complexity, since it checks if
// std funcs such as lower_bound meets prereqs

using namespace atcoder;
int L[10005];
int R[10005];
int V[10005];
ll op(ll a, ll b) { return max(a, b); }

ll e() { return (ll)(-INF); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int n, w;
  segtree<ll, op, e> seg(10005);
  segtree<ll, op, e> seg2(10005);
  cin >> w >> n;
  rep(i, n) cin >> L[i] >> R[i] >> V[i];
  seg.set(0, 0);
  seg2.set(0, 0);
  rep(i, n) {
    rep(j, 10001) {
      ll now;
      if (i & 1)
        now = seg2.get(j);
      else
        now = seg.get(j);
      int l = max(0, j - R[i]);
      int r = max(0, j - L[i]);
      if (l > r + 1 or r == 0)
        continue;
      ll nx;
      if (i & 1)
        nx = seg2.prod(l, r + 1) + V[i];
      else
        nx = seg.prod(l, r + 1) + V[i];
      chmax(now, nx);
      if (i & 1)
        seg.set(j, now);
      else
        seg2.set(j, now);
    }
  }
  ll ans;
  if (!(n & 1))
    ans = seg.get(w);
  else
    ans = seg2.get(w);
  if (ans == -INF)
    ans = -1;
  cout << ans << nl;
  return 0;
}
