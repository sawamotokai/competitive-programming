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
// abc37d


int dp[1004][1004];
int a[1004][1004];
int mod = 1e9+7;
int h,w;

ll dfs(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  ll ret = 1;
  int dx[4] = {0,1,0,-1};
  int dy[4] = {1,0,-1,0};
  rep(k, 4) {
    int nx = j + dx[k];
    int ny = i + dy[k];
    if (nx >= w || ny >= h) continue;
    if (a[ny][nx] <= a[i][j]) continue;
    (ret += dfs(ny, nx)) %= mod;
  }
  return dp[i][j] = ret;
}

int main() {
  cin >> h >> w;
  memset(dp, -1, sizeof(dp));
  rep(i, h) rep(j, w) scanf("%d", &a[i][j]);
  int mx = 0;
  int mn = INF;
  int x = 0, y =0;
  int x2 = 0, y2 = 0;
  rep(i, h) rep(j, w) {
    if (a[i][j] > mx) {
      mx = a[i][j];
      y = i, x = j;
    }
    if (a[i][j] < mn) {
      mn = a[i][j];
      x2 = j, y2 = i;
    }
  }
  dp[y][x] = 1;
  int ans = 0;
  rep(i, h) rep(j, w) {
    (ans+=dfs(i,j))%=mod;
  }
  cout << ans << endl;
  return 0;
}