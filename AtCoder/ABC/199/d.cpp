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
// // Assumes little endian
void printBits(size_t const size, void const *const ptr) {
  unsigned char *b = (unsigned char *)ptr;
  unsigned char byte;
  int i, j;

  for (i = size - 1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  puts("");
}
vi to[105];
int e[105][105];
ll ans = 0;
int n, m;
void f(int bit) {
  if (__builtin_popcountll(bit) < 2)
    return;
  vi same;
  vi dif;
  rep(i, n) {
    if ((bit >> i) & 1)
      same.pb(i);
    else
      dif.pb(i);
  }
  ll now = 3;
  for (int v : same) {
    for (int u : same) {
      if (u == v)
        continue;
      if (e[v][u])
        return;
    }
  }
  int zero = 0;
  vi vis(n);
  auto bfs = [&](int i) {
    queue<int> q;
    q.push(i);
    while (q.size()) {
      auto v = q.front();
      q.pop();
      for (int u : to[v]) {
        if (!vis[u])
          q.push(u);
        vis[u] = 1;
      }
    }
  };
  rep(i, n) {
    if (!vis[i])
      zero++;
    else
      continue;
    vis[i] = 1;
    bfs(i);
  }

  rep(i, zero) now <<= 1;
  ans += now;
  printBits(sizeof(bit), &bit);
  cout << now << nl;
}

void dfs(int v) {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    e[a][b] = 1;
    e[b][a] = 1;
    to[a].pb(b);
    to[b].pb(a);
  }
  rep(i, n) {}
  rep(i, 1 << n) { f(i); }
  cout << ans << nl;
  return 0;
}
