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


// abc74d
int main() {
  int n; cin >> n;
  vvi a(n, vi(n));
  rep(i,n) rep(j,n) cin >> a[i][j];
  vector<vll> dp(n, vll(n, INF));
  rep(i, n) rep(j, n) {
    dp[i][j] = a[i][j];
  }
  rep(k, n) rep(i, n) rep(j, n) chmin(dp[i][j], dp[i][k] + dp[k][j]);

  // rep(i, n){
      // rep(j, n) {
        // cout << dp[i][j] << " ";
      // }
    // cout << endl;
  // }
  rep(i, n) rep(j, n) {
    if (i==j) continue;
    if (dp[i][j] < a[i][j]) {
      cout << -1 << endl;
      return 0;
    }
  }
  ll ans = 0;
  rep(i, n) rep(j, n) ans+=a[i][j];
  rep(i,n) {
    rep(j, n) {
      if (i==j )continue;
      int path = a[i][j];
      rep(k,n) {
        if (k==i || k==j) continue;
        ll detour = dp[i][k] + dp[k][j];
        if (detour == path) {
          ans -= path;
          break;
        } if (detour < path) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  ans /=2;
  printf("%lld\n",ans);
  return 0;
}