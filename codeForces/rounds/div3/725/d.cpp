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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<P> factors(int n) {
  int t = n;
  vector<P> ret;
  if (n == 1)
    return ret;
  for (ll i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (t % i == 0) {
      t /= i;
      cnt++;
    }
    if (cnt) {
      ret.emplace_back(i, cnt);
    }
  }
  if (t == n) {
    ret.emplace_back(t, 1);
  }
  return ret;
}

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  int g = gcd(a, b);
  vector<P> fa = factors(a);
  vector<P> fb = factors(b);
  vector<P> fg = factors(g);
  int sg = 0;
  int sa = 0;
  int sb = 0;
  for (auto p : fg)
    sg += p.se;
  for (auto p : fa)
    sa += p.se;
  for (auto p : fb)
    sb += p.se;
  int lo = 2;
  if (g == a or g == b)
    lo = 1;
  if (a == b)
    lo = 2;
  int hi = sa + sb;
  // print({sa, sb, sg, lo, hi});
  if (k == 1) {
    if ((sa == sg or sb == sg) and (sa != sg or sb != sg)) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
    return;
  }
  if (k >= lo and k <= hi) {
    cout << "YES" << nl;
  } else {
    cout << "NO" << nl;
  }
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
