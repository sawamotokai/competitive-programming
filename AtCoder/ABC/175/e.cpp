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

int R,C,K;
ll dp[3005][3005][4];
int main() {
  cin >> R >> C>> K;
  vector<vll> grid(R,vll(C));
  rep(i,K) {
    int r,c,v; cin >> r >> c >> v;
    r--, c--;
    grid[r][c] = v;
  }
  rep(i,R) rep(j,C) {
    rep(k,4) {
      // taking 
      if (k != 3) {
        chmax(dp[i+1][j][0], dp[i][j][k] + grid[i][j]);
        chmax(dp[i][j+1][k+1], dp[i][j][k] + grid[i][j]);
      }
      // not taking
      chmax(dp[i+1][j][k], dp[i][j][k]);
      chmax(dp[i][j+1][k], dp[i][j][k]);
    }
  }
  rep(i,4) if(i!=3) dp[R-1][C-1][i] += grid[R-1][C-1];
  ll ans = 0;
  rep(i,4) {
    chmax(ans, dp[R-1][C-1][i]);
  }
  cout << ans << endl;
  return 0;
}