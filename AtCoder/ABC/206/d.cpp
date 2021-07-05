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
struct UnionFind {
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {}
  int find(int x) {
    if (d[x] < 0)
      return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (d[x] > d[y])
      swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
  int numSets() {
    int c = 0;
    for (int num : d)
      if (num < 0)
        c++;
    return c;
  }
};

void _main() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  UnionFind uf(2e6 + 1);
  // maps num to idx of first occurance + 1
  map<int, int> mp;
  rep(i, n) {
    if (mp[a[i]] == 0)
      mp[a[i]] = i + 1;
  }

  rep(i, n / 2 + 1) {
    if (a[i] != a[n - i - 1]) {
      uf.unite(a[i], a[n - i - 1]);
    }
  }
  int ans = 0;
  for (int num : uf.d) {
    if (num < 0) {
      ans += abs(num) - 1;
    }
  }
  cout << ans << nl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int t = 1;
  // cin >> t;
  while (t--)
    _main();
  return 0;
}

class segment_tree {
private:
  int sz;
  std::vector<int> seg;
  std::vector<int> lazy;
  void push(int k) {
    if (k < sz) {
      lazy[k * 2] = max(lazy[k * 2], lazy[k]);
      lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
    }
    seg[k] = max(seg[k], lazy[k]);
    lazy[k] = 0;
  }
  void update(int a, int b, int x, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l)
      return;
    if (a <= l && r <= b) {
      lazy[k] = x;
      push(k);
      return;
    }
    update(a, b, x, k * 2, l, (l + r) >> 1);
    update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
    seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
  }
  int range_max(int a, int b, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l)
      return 0;
    if (a <= l && r <= b)
      return seg[k];
    int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
    int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
    return max(lc, rc);
  }

public:
  segment_tree() : sz(0), seg(), lazy(){};
  segment_tree(int N) {
    sz = 1;
    while (sz < N) {
      sz *= 2;
    }
    seg = std::vector<int>(sz * 2, 0);
    lazy = std::vector<int>(sz * 2, 0);
  }
  void update(int l, int r, int x) { update(l, r, x, 1, 0, sz); }
  int range_max(int l, int r) { return range_max(l, r, 1, 0, sz); }
};
