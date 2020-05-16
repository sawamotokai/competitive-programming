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


// BFS but find dist st we can get to V in mod 3 moves.

vi to[100005];

int main() {
  int N, M; cin >>N>>M;
  rep(i,M) {
    int u, v; cin >> u>> v;
    u--; v--;
    to[u].push_back(v);
  }
  int S, T; cin >> S>>T;
  S--;T--;
  vvi dist(N, vi(3, INF));
  dist[S][0] = 0;
  queue<ii> q;
  q.push({S, 0});
  while (q.size()) {
    int v = q.front().first; 
    int l = q.front().second; q.pop();
    int nl = (l+1)%3;
    for (int u: to[v]) {
      if (dist[u][nl] != INF) continue;
      dist[u][nl] = dist[v][l] + 1;
      q.push({u, nl});
    }
  }
  int ans;
  if (ans == INF) ans = -1;
  else  ans = dist[T][0]/3;
  cout << ans << endl;
  return 0;
}