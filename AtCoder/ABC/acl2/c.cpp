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
};
int N, M;
int main() {
  cin >> N >> M;
  UnionFind uf(N);
  int ans = N;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (!uf.same(a, b))
      ans--;
    uf.unite(a, b);
  }
  cout << ans - 1 << endl;
  return 0;
}
