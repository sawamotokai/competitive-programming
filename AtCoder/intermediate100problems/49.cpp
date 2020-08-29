#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

struct edge {
  int from, w;
  edge(int from, int w):from(from),w(w){};
};

int V,E;
int dist[20][20];
int dp[1<<20][20][20];
vector<edge> to[24];

int rec(int bits, int v, int p) {
  if (~dp[bits][v][p]) return dp[bits][v][p];
  if (bits == 1 << v) return dp[bits][v][p] = 0;
  int prev = bits & ~(1 << v);
  int ret = INF;
  for (edge e: to[v]) {
    int u = e.from;
    int w = e.w;
    // if (u == p) continue;
    if (!(prev & (1<<u))) continue; // if u is not in prev bits continue
    chmin(ret, rec(prev, u, p) + w);
  }
  return dp[bits][v][p] = ret;
}


int main() {
  cin >> V >> E;
  rep(i,E) {
    int a,b,c; cin >> a >> b >> c;
    to[b].emplace_back(a,c);
  }
  memset(dp,-1,sizeof(dp));
  int ans = INF;
  rep(i,V) rep(j,V) {
    if (i == j)
      continue;
    int now = rec((1 << V) - 1, i, j);
    for (edge e: to[i]) {
      if (e.from == j) now += e.w;
    }
    chmin(ans, now);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}