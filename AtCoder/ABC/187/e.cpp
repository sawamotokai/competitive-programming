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

int N;
vector<int> to[200005];
ll W[200005];
ll pena[200005];
ll dp[200005];

// ll rec(int v, int from = -1) {
//   if (dp[v] != -INF)
//     return dp[v];
//   ll now = W[v];
//   for (int u : to[v]) {
//     // if (u == from)
//     //   continue;
//     if (W[u] <= 0)
//       continue;
//     now += rec(u, v);
//   }
//   return dp[v] = now;
// }

ll dfs(int v, int root = -1) {
  ll now = W[v] + pena[v];
  for (int u : to[v]) {
    if (root == u)
      continue;
    if (dp[u] != -INF)
      now += dp[u];
    else
      now += dfs(u, v);
  }
  if (root == -1)
    dp[v] = now;
  return now;
}

int main() {
  cin >> N;
  vi A(N);
  vi B(N);
  rep(i, 2e5 + 3) dp[i] = -INF;
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
    A[i] = a;
    B[i] = b;
  }
  int Q;
  cin >> Q;
  while (Q--) {
    ll t, e, x;
    cin >> t >> e >> x;
    e--;
    ll a = A[e];
    ll b = B[e];
    if (t == 1) {
      W[a] += x;
      // W[b] -= x;
      pena[b] -= x;
    } else {
      // W[a] -= x;
      pena[a] -= x;
      W[b] += x;
    }
  }
  rep(i, N) dfs(i);
  rep(i, N) cout << dp[i] << endl;
  // rep(i, N) cout << W[i] << endl;
  return 0;
}
