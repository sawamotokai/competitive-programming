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
struct edge {
  int v;
  int c;
  edge(int v, int c) : v(v), c(c){};
};
vector<edge> to[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    to[a].emplace_back(b, c);
    to[b].emplace_back(a, c);
  }
  vi dist(n, INF);
  dist[0] = 0;
  minq<P> pq;
  pq.emplace(0, 0);
  while (pq.size()) {
    int d = pq.top().fi;
    int v = pq.top().se;
    pq.pop();
    for (edge e : to[v]) {
      if (chmin(dist[e.v], dist[v] + e.c)) {
        pq.emplace(dist[e.v], e.v);
      }
    }
  }
  vi dist2(n, INF);
  dist2[n - 1] = 0;
  pq.emplace(0, n - 1);
  while (pq.size()) {
    int d = pq.top().fi;
    int v = pq.top().se;
    pq.pop();
    for (edge e : to[v]) {
      if (chmin(dist2[e.v], dist2[v] + e.c)) {
        pq.emplace(dist2[e.v], e.v);
      }
    }
  }
  rep(k, n) { cout << dist[k] + dist2[k] << nl; }
  return 0;
}
