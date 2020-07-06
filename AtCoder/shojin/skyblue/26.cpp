#include <bits/stdc++.h>
#include <cassert>
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
// abc117d
ll dp[51][2];
int main() {
  ll n,k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  int bits = 45;
  memset(dp, -1, sizeof(dp));
  dp[bits][0] = 0;
  for (int i=bits-1; i>=0; --i) {
    // num of 1's of a[j][i] for j <- 0..n-1
    int cnt = 0;
    rep(l, n) if ((a[l] >> i) & 1) cnt++;
    // If you make a 0, it increses by # of 1's * keta; if you make a 1 # of 0's
    // 0->0
    ll digit = 1ll << i;
    if (dp[i+1][0] >= 0) {
      chmax(dp[i][0], dp[i+1][0] + (ll) (cnt)*digit); // x[i] = 0
      chmax(dp[i][0], dp[i+1][0] + (ll) (n-cnt)*digit); // x[i] = 1
    } 
    // 1->0
    if (dp[i+1][1] >= 0) {
      if ((k >> i)&1) {
        chmax(dp[i][0], dp[i+1][1] + (ll)(cnt) * digit); // x[i] = 0
      }
      // 1->1
      if ((k>>i) & 1) chmax(dp[i][1], dp[i+1][1] + (ll)(n - cnt) * digit);
      else chmax(dp[i][1], dp[i+1][1] + (ll)(cnt) * digit);
    }
  }
  ll ans = max(dp[0][0], dp[0][1]);
  cout << ans << endl;
  return 0;
}