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
int ans = 0;
vb visited;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  while(q.size()) {
    int u = q.front(); q.pop();
    visited[u] = true;
    for (int v : to[u])
    {
      if (!visited[v]) {
        q.push(v);
      }
    }
  }
}

int main() {
  int n,m; cin >>n>>m;
  rep(i,m) {
    int x,y,z; cin >> x >> y >> z;
    x--; y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  visited.resize(n, false);
  rep(i,n) {
    if (!visited[i]) {
      bfs(i);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}