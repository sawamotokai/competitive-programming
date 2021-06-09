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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  int q;
  cin >> q;
  auto f = [&](int y, int x) { return x + y * w; };
  UnionFind uf(h * w);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      grid[r][c] = '#';
      rep(i, 4) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (nr < 0 or nr >= h or nc < 0 or nc >= w)
          continue;
        if (grid[nr][nc] == '#')
          uf.unite(f(nr, nc), f(r, c));
      }
    } else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;
      ca--;
      rb--;
      cb--;
      if (grid[ra][ca] == '#' and grid[rb][cb] == '#' and
          uf.same(f(ra, ca), f(rb, cb))) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
    }
  }
  return 0;
}
