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
  cin >> x;
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
vi to[100005];
vi rev[100005];
int V[100005];
int vis[100005];
int N, M;
int id = 0;
ll ans = 0;
ll num = 1;

void dfs(int v, int from = -1) {
  for (int u : to[v]) {
    if (vis[u])
      continue;
    vis[u] = 1;
    dfs(u, v);
  }
  V[v] = id;
  id++;
}

void dfs2(int v) {
  num++;
  // print({v, (int)num});
  for (int u : rev[v]) {
    if (vis[u])
      continue;
    vis[u] = 1;
    dfs2(u);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  memset(V, -1, sizeof(V));
  cin >> N >> M;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    rev[b].push_back(a);
  }
  rep(i, N) {
    if (vis[i])
      continue;
    vis[i] = 1;
    dfs(i);
  }

  priority_queue<P> pq;
  rep(i, N) { pq.emplace(V[i], i); }

  memset(vis, 0, sizeof(vis));
  while (pq.size()) {
    auto [idx, i] = pq.top();
    pq.pop();
    if (vis[i])
      continue;
    vis[i] = 1;
    num = 1;
    for (int u : rev[i]) {
      if (vis[u])
        continue;
      vis[u] = 1;
      dfs2(u);
    }
    ans += num * (num - 1) / 2;
  }
  cout << ans << nl;
  return 0;
}
