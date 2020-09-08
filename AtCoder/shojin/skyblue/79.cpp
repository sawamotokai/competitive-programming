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
string grid[505];
int dp[505][505];
int main() {
  cin >> H >> W;
  rep(i,H) rep(j,W) dp[i][j] = INF;
  rep(i,H) cin >> grid[i]; 
  int si=-1;
  int sj=-1;
  int gi=-1;
  int gj=-1;
  rep(i, H) rep(j, W) {
    if (grid[i][j] == 's') {
      si = i;
      sj = j;
    }
    if (grid[i][j] == 'g') {
      gi = i;
      gj = j;
    }
  }
  deque<ii> q;
  q.eb(si,sj);
  dp[si][sj] = 0;
  while (q.size()) {
    auto [i,j] = q.front();
    q.pop_front();
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    rep(k,4) {
      int ni = i + dy[k];
      int nj = j + dx[k];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
      if (grid[ni][nj] == '.'|| grid[ni][nj] == 'g') {
        if (chmin(dp[ni][nj], dp[i][j])) q.emplace_front(ni,nj);
      } 
      if (grid[ni][nj] == '#' ) {
        if (chmin(dp[ni][nj], dp[i][j] + 1)) q.emplace_back(ni,nj);
      }
    }
  }
  if (dp[gi][gj] <= 2) {
    cout << "YES" <<endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}