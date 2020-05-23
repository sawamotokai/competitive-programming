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

int main() {
  int N,X,Y; cin >> N>>X>>Y;
  X+=250; Y+=250;
  // origine(250, 250)
  vector<string> maze(5000, string(5000, '.'));
  rep(i,N) {
    int x,y; cin >> x >> y;
    x+=250; y+=250;
    maze[x][y] = '#';
  }
  if (maze[X][Y+1] == '#' && maze[X+1][Y] == '#' && maze[X+1][Y-1] == '#' && maze[X][Y-1]=='#' && maze[X-1][Y-1] == '#' && maze[X-1][Y] == '#') {
    cout << -1 << endl;
    return 0;
  }
  vvi dist(5000, vi(5000, INF));
  dist[250][250] = 0;
  queue<ii> q;
  q.push({250, 250});
  int dx[] = {0, 1, 1, 0, -1, -1}, dy[] = {1,1,0,-1,0,1};
  while (q.size() && dist[X][Y] == INF) {
    int x = q.front().first; int y = q.front().second; q.pop();
    rep(i,6) {
      int nx = x + dx[i], ny = y+dy[i];
      if (nx < 0 || ny < 0 || nx > 500 || ny > 500) continue;
      if (maze[nx][ny] == '#' || dist[nx][ny] != INF) continue;
      dist[nx][ny] = 1 + dist[x][y];
      q.push({nx,ny});
    } 
  }

  int ans = dist[X][Y];
  if (ans == INF) ans = -1;
  cout << ans << endl;
 return 0;
}