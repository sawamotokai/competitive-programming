#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

vi color;
vector<vector<int>> g;
vvi dist;

void dfs(int u = 0, int len = 0)
{
  for (int i=0; i<g[u].size(); i++)
  {
    int v = g[u][i];
    if (v == u)
      continue;
    if (color[v] != -1) continue;
    color[v] = (len + dist[u][i])%2;
    dfs(v, (len+dist[u][i])%2);
  }
}

int main() {
  int n; cin >> n;
  g.resize(n);
  color.resize(n, -1);
  dist.resize(n);
  color[0] = 0;
  rep(i,n-1) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    dist[u].push_back(w);
    dist[v].push_back(w);
  }
  dfs();
  rep(i,n) cout << color[i] << endl;
  return 0;
}