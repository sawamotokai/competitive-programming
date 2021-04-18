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
using minq = priority_queue<P, vector<P>, gt>;
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
inline void priv(vi a) {
  rep(i, (int)a.size() - 1) { cout << a[i] << " "; }
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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  int mod = 1e9 + 7;
  vi b = a;
  sort(all(b));
  takeUnique(b);
  int n2 = b.size();

  if (n2 == 1) {
    ans = 1;
    rep(i, n)(ans *= i + 1) %= mod;
    cout << ans << nl;
    return;
  }
  vi le(n2);
  vi ri(n2);
  le[1] = a[0];
  ri[n2 - 2] = a.back();
  rep2(i, 2, n2 - 1) { le[i] = le[i - 1] & a[i - 1]; }
  rep3(i, n2 - 3, 0) { ri[i] = ri[i + 1] & a[i + 1]; }
  map<int, int> mp;
  map<int, bool> processed;
  rep(i, n) { mp[a[i]]++; }
  ll inner = 1;
  rep(i, n - 2) { (inner *= i + 1) %= mod; }
  int any = 0;
  rep2(i, 0, n2 - 1) {
    if (processed[b[i]])
      continue;
    processed[b[i]] = true;
    ll now = (1ll << 32) - 1;
    if (i == 0)
      now &= ri[i];
    else if (i == n - 1)
      now &= le[i];
    else
      now &= ri[i] & le[i];
    if (mp[b[i]] > 2) {
      now &= b[i];
    }
    if (now == b[i]) {
      ll t = 1;
      any = 1;
      (t *= inner) %= mod;
      rep3(j, mp[b[i]], mp[b[i]] - 1) { (t *= j) %= mod; }
      (ans += t) %= mod;
    }
  }
  if (!any)
    ans = 0;
  cout << ans << nl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
