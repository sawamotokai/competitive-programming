#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 
// ACGT
// no -> ?102, ?021, ?012, 0?12, 01?2
int dp[105][4][4][4];
int mod = 1e9+7;

int main() {
  int n; cin >> n;
  dp[0][3][3][3] = 1;
  rep(i,n) {
    rep(d1,4) rep(d2,4) rep(d3,4) {
      rep(a, 4) {
        if (d2 == 1 && d3 == 0 && a==2) continue;
        if (d2 == 0 && d3 == 2 && a==1) continue;
        if (d2 == 0 && d3 == 1 && a==2) continue;
        if (d1 == 0 && d3 == 1 && a==2) continue;
        if (d1 == 0 && d2 == 1 && a==2) continue;
        (dp[i+1][d2][d3][a] += dp[i][d1][d2][d3]) %= mod;
      }
    }
  }
  int ans = 0;
  rep(d1,4)
  rep(d2,4)
  rep(d3,4) {
    (ans += dp[n][d1][d2][d3]) %= mod;
  }
  cout << ans << endl;
  return 0;
}