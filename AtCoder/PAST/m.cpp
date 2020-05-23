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

vi to[100005];
bool visited[17];
ll ans =0;
int k;
int n;
int findDist(int u, int v) {
  vi dist(n, INF);
  dist[u] = 0;
  queue<int> q;
  q.push(u);
  while(q.size() && dist[v] == INF) {
    int x = q.front(); q.pop();
    for (int nx: to[x]) {
      if (dist[nx] != INF) continue;
      dist[nx] = dist[x] + 1;
    }
  }
  return dist[v];
}

void dfs(vi t) {
  if (t.size()==k) {
    ll dist =0;
    for (int i=0; i<k-1; i++) {
      dist+= findDist(t[i], t[i+1]);
    }
    ans = min (ans, dist);
    return ;
  }
  rep(i, k) {
    if (visited[i]) continue;
    visited[i] = true;
    t.push_back(i);
    dfs(t);
    t.pop_back();
    visited[i] = false;
  }
}

int main() {
  int m; cin >> n >> m;
  rep(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  int s; cin >> s;
  cin >> k;
  s--;
  vi t(k);
  t.push_back(s);
  rep(i,k) {
    cin >> t[i]; t[i]--;
  }
  visited[s] = true;
  dfs(t);
  cout << ans << endl;
  return 0;
}