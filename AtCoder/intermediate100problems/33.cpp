#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
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

int H,W;
string grid[51];
int dist[51][51];

int main() {
  cin >> H >> W;
  rep(i,H) cin >> grid[i];
  int path = INF;
  int black = 0;
  rep(i,H)rep(j,W) {
    if (grid[i][j] == '#') black++;
    dist[i][j]=INF;    
  }
  dist[0][0] = 0;
  queue<ii> q;
  q.emplace(0,0);
  while(q.size()) {
    auto [i,j] = q.front(); q.pop();
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    rep(k,4) {
      int ni = i+dy[k];
      int nj = j+dx[k];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W || dist[ni][nj] != INF || grid[ni][nj] == '#') continue;
      q.emplace(ni,nj);
      dist[ni][nj] = dist[i][j] + 1;
    }
  }
  int ans = H*W - black - dist[H-1][W-1] - 1;
  if (dist[H-1][W-1] == INF) ans = -1;
  cout << ans << endl;
  return 0;
}