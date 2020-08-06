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

// abc20c
int main() {
  int H,W,T;cin>>H>>W>>T;
  vector<string> grid(H);
  rep(i,H)cin>>grid[i];
  int ans = 0;
  int sx=-1,sy=-1;
  int gx=-1,gy=-1;
  rep(i,H) rep(j,W) {
    if (grid[i][j] == 'S') sy = i, sx = j;
    if (grid[i][j] == 'G') gy = i, gx = j;
  }
  auto f = [&](int X) {
    vector<vll> dist(H, vll(W,INF));
    dist[sy][sx]=0;
    queue<ii> q;
    q.emplace(sy,sx);
    while(q.size()) {
      int y = q.front().first, x = q.front().second; q.pop();
      int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
      rep(i,4) {
        int nx = dx[i] + x, ny = dy[i] + y;
        if (nx >= W || nx < 0 || ny >= H || ny < 0) continue;
        ll nd = dist[y][x];
        if (grid[ny][nx] == '#') nd += X;
        else nd++;
        if (dist[ny][nx] <= nd) continue;
        dist[ny][nx] = nd;
        q.emplace(ny,nx);
      }
    }
    return T >= dist[gy][gx];
  };
  int hi = INF;
  int lo = 0;
  rep(i,100) {
    int mid = (hi+lo) / 2;
    if (f(mid)) lo = mid;
    else hi = mid;
    ans = mid;
  }
  cout << ans << endl;
  return 0;
}