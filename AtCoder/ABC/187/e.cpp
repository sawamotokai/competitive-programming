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
//
vi to[200005];
int d[200005];
ll ans[200005];

void add(int v, int from = -1) {
  for (int u : to[v]) {
    if (u == from)
      continue;
    ans[u] += ans[v];
    add(u, v);
  }
}
void dfs(int v, int from = -1) {
  for (int u : to[v]) {
    if (u == from)
      continue;
    chmin(d[u], d[v] + 1);
    dfs(u, v);
  }
}

int main() {
  int n;
  cin >> n;
  rep(i, n) d[i] = INF;
  d[0] = 0;
  vi a(n - 1);
  vi b(n - 1);
  rep(i, n - 1) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    to[a[i]].pb(b[i]);
    to[b[i]].pb(a[i]);
  }
  dfs(0);
  int q;
  cin >> q;
  while (q--) {
    int t, i, x;
    cin >> t >> i >> x;
    i--;
    int avoid;
    int v;
    if (t == 1) {
      avoid = b[i];
      v = a[i];
    } else {
      avoid = a[i];
      v = b[i];
    }
    if (d[avoid] < d[v]) {
      ans[v] += x;
    } else {
      ans[0] += x;
      ans[avoid] -= x;
    }
  }
  add(0);
  rep(i, n) cout << ans[i] << '\n';
  return 0;
}
