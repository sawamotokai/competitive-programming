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
//

int N;

struct edge {
  int v;
  ll w;
  edge(int v, ll w) : v(v), w(w){};
};

vector<edge> to[100005];
ll dist[100006];

void dfs(int u, int p = -1) {
  for (edge e : to[u]) {
    if (e.v == p)
      continue;
    dist[e.v] = dist[u] + e.w;
    dfs(e.v, u);
  }
}

void solve() {
  int x, y;
  cin >> x >> y;
  x--, y--;
  cout << dist[x] + dist[y] << endl;
}

int main() {
  cin >> N;
  rep(i, N - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    to[a].eb(b, c);
    to[b].eb(a, c);
  }
  int Q, K;
  cin >> Q >> K;
  K--;
  rep(i, 100003) dist[i] = LINF;
  dist[K] = 0;
  dfs(K);

  while (Q--) {
    solve();
  }
  return 0;
}
