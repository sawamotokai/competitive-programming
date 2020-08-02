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
// struct edge {
//   int to;
//   ll w;
//   edge(int to, ll w):to(to), w(w){}
// };
// struct vertex {
//   int v;
//   ll val;
//   vertex(int v, ll val):v(v), val(val){}
//   bool operator<(const vertex rhs) {
//     return this->val > rhs.val;
//   }
// };

// vector<edge> g[100005];
int main() {
  cin >> N >> M;
  vvi dist1(N, vi(N, INF));
  vvi dist2(N, vi(N, INF));
  rep(i,N) dist1[i][i] = dist2[i][i] = 0;
  rep(i,M) {
    int a,b,c; cin >> a >> b >> c; a--; b--;
    dist1[a][b] = c;
    dist2[b][a] = c;
  }
  rep(k,N) rep(i,N) rep(j,N) {
    chmin(dist1[i][j], dist1[i][k] + dist1[k][j]);
    chmin(dist2[i][j], dist2[i][k] + dist2[k][j]);
  }
  int ans = INF;
  rep(i,N) {
    if (i == 0) continue;
    chmin(ans, dist1[0][i] + dist2[0][i]);
  }
  rep(i,N) {
    rep(j,N)cout<<dist1[i][j] << " ";
    cout << endl;
  }
  cout << ans << endl;
  return 0;
}