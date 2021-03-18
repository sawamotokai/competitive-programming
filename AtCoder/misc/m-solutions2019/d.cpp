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
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++
vi to[10005];
int deg[10005];
int used[10005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  vi c(n);
  rep(i, n) cin >> c[i];
  priority_queue<int, vi, greater<int>> pq;
  rep(i, n) pq.push(c[i]);
  queue<int> leaves;
  vi ans(n);
  rep(i, n) {
    if (deg[i] == 1) {
      leaves.push(i);
      used[i] = 1;
      ans[i] = pq.top();
      pq.pop();
    }
  }
  ll m = 0;
  while (leaves.size()) {
    int v = leaves.front();
    leaves.pop();
    for (int u : to[v]) {
      if (used[u])
        continue;
      ans[u] = pq.top();
      pq.pop();
      deg[u]--;
      if (deg[u] == 1) {
        leaves.push(u);
        used[u] = 1;
      }
    }
  }
  rep(i, n) {
    for (int u : to[i]) {
      m += min<ll>(ans[i], ans[u]);
    }
  }
  cout << m / 2 << nl;
  priv(ans);
  return 0;
}
