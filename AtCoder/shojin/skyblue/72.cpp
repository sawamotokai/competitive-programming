#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
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

int N,M;
vi to[100006];
int main() {
  cin >> N >> M;
  vvi dist(N, vi(N, INF));
  vvi dist2(N, vi(N, INF));
  rep(i,N) dist[i][i]=0;
  rep(i,M) {
    int a,b,c; cin >> a >> b >> c; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
    if (a == 0 || b == 0) {
      dist2[a][b] = c;
      dist2[b][a] = c;
      continue;
    }
    dist[a][b] = c;
    dist[b][a] = c;

  }
  rep(k,N) rep(i,N) rep(j,N) {
    chmin(dist[i][j], dist[i][k] + dist[k][j]);
  }
  int ans = INF;
  for (int v: to[0]) {
    for (int u: to[0]) {
      if (v==u) continue;
      chmin(ans, dist[v][u] + dist2[0][v] + dist2[0][u]);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}