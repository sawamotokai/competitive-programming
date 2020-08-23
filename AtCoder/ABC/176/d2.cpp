
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


// 0,1 bfs
int main() {
  cin >> H>>W>>Ch>>Cw>>Dh>>Dw;
  Ch--,Cw--,Dh--,Dw--;
  rep(i,H) cin >> grid[i];
  vvi cost(H, vi(W, INF));
  deque<ii> q;
  q.push_back({Ch,Cw});
  cost[Ch][Cw] = 0;
  while(q.size()) {
    auto[i,j] = q.front();
    q.pop_front();
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    rep(k,4) {
      int ni = i + dy[k];
      int nj = j + dx[k];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W || grid[ni][nj] == '#') continue;
      if (chmin(cost[ni][nj], cost[i][j])) q.push_front({ni, nj});
    }
    for (int dx = -2; dx<=2; dx++) {
      for (int dy = -2; dy<=2; dy++) {
        int ni = dy + i;
        int nj = dx + j;
        if (ni < 0 || ni >= H || nj < 0 || nj >= W || grid[ni][nj] == '#') continue;
        if (chmin(cost[ni][nj], 1+cost[i][j])) q.push_back({ni, nj});
      }
    }
  }
  int ans = cost[Dh][Dw];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}