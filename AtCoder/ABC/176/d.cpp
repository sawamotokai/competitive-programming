#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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

int H,W,Ch,Cw,Dh,Dw;
string grid[1005];
int clr[1005][1006];
int visited[1005][1006];

void bfs(int ai, int aj, int color){
  queue<ii> q;
  q.emplace(ai,aj);
  while(q.size()) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    rep(k,4) {
      int ni = i+dy[k];
      int nj = j+dx[k];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
      if (grid[ni][nj] == '#' || clr[ni][nj] != 0) continue;
      clr[ni][nj] = color;
      q.emplace(ni, nj);
    }
  }
}


int main() {
  cin >> H>>W>>Ch>>Cw>>Dh>>Dw;
  Ch--,Cw--,Dh--,Dw--;
  rep(i,H) cin >> grid[i];

  int color = 1;
  rep(i,H) rep(j,W) {
    if (clr[i][j] != 0) continue;
    if (grid[i][j] == '#') continue;
    clr[i][j] = color;
    bfs(i,j,color);
    color++;
  }
  if (clr[Ch][Cw] == clr[Dh][Dw]) {
    cout << 0 << endl;
    return 0;
  }


  queue<ii> q;
  queue<ii> nx;
  // clr[ai][aj] = -1; 
  vvi dist(H,vi(W,INF));
  dist[Ch][Cw] = 0;
  nx.emplace(Ch,Cw);
  int level = 0;

  while(nx.size()) {
    swap(q,nx);
    while (q.size()) {
      auto [i,j] = q.front();
      q.pop();
      for (int dy=-2;dy<=2; dy++) {
        for (int dx=-2;dx<=2; dx++) {
          int ni = i+dy;
          int nj = j+dx;
          if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
          if (grid[ni][nj] == '#') continue;
          if (clr[ni][nj] == clr[i][j]) {
            if(chmin(dist[ni][nj], dist[i][j])) q.emplace(ni, nj);
          } else {
            if (chmin(dist[ni][nj], dist[i][j] + 1)) nx.emplace(ni,nj);
          }
        }
      }
    }
  }

  ll ans = dist[Dh][Dw];
  if (ans == INF) ans =-1;
  cout << ans <<endl;
  return 0;
}