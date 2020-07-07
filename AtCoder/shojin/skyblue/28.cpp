// agin progrmaing contest 2019

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

// AISing programming contest
bool visited[405][405];
int main() {
  int h,w; cin >> h >> w;
  vector<string> maze(h);
  rep(i,h) cin >> maze[i];

  vector<P> groups;
  auto bfs = [&](ii xy) {
    ll black = 0, white = 0;
    queue<ii> q;
    q.push(xy);
    visited[xy.second][xy.first] = true;
    while (q.size()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      if (maze[y][x] == '#') black++;
      else white++;
      int dx[] = {0,1,0,-1};
      int dy[] = {1,0,-1,0};
      rep(i, 4) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if ( ny<0 || ny >= h || nx < 0 || nx >= w || visited[ny][nx]) continue;
        if (maze[y][x] == maze[ny][nx]) continue;
        q.emplace(nx, ny);
        visited[ny][nx] = true;
      }
    }
    groups.emplace_back(black, white);
  };

  rep(i,h) rep(j,w) {
    if (!visited[i][j]) {
      // cout << j << " "<< i << endl;
      bfs({j,i});
    }
  }
   
  ll ans = 0;
  for (auto p: groups) {
    ans += p.first * p.second;
  }
  printf("%lld\n", ans);
  return 0;
}