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


// abc073d
vi to[305];
int dist[305][305];
int n,m,r;
bool used[10];
int village[10];
int ans = INF;
void dfs(int v=-1, int num=0, int sum=0)  {
  if (num == r) {
    chmin(ans, sum);
    return;
  }   
  rep(i, r) {
    if (i==v) continue;
    if (used[i])continue;
    used[i] = true;
    int ns;
    if (v!=-1) ns = sum + dist[village[i]][village[v]];
    else ns = 0;
    dfs(i, num+1, ns);
    used[i] =false;
  }
}

int main() {
   cin >> n >> m >> r;
  rep(i,n) rep(j, n) {
    dist[i][j] = INF;
    if (j==i) dist[i][j] = 0;
  }
  rep(i,r) {
    cin >> village[i];
    village[i]--;
  }
  rep(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
    dist[a][b] = c;
    dist[b][a] = c; 
    } 
    rep(k, n)rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][k]+dist[k][j]); 
  dfs();
  cout << ans << endl;
  return 0;
}