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

ll dp[10000][85];
// unordered_map<ii, ll> dp;

int main() {
  int n; cin >> n;
  memset(dp, -1, sizeof(dp));
  vi a(n);
  rep(i,n ) cin >> a[i];
  // ll rest = 1000;
  dp[0][0] = 1000;
  ll maxRest = 1000;
  ll maxStock = 0;
  rep(i,n) {
    int maxBuy = maxRest/a[i];   
    for (int j=0; j <= maxBuy ; j++) {
      rep(s, maxStock+1) {
        if (dp[s][i] == -1) break;
        ll ns = s+j;
        chmax(dp[ns][i+1], dp[s][i] - j * a[i]);
        chmax(maxStock, ns);
      }
    }
    for (int j=0; j <= maxStock; j++) {
      if (dp[j][i] == -1) break; // TODO: iffy
      rep(sell, j+1) {
        ll nm = dp[j][i] + sell*a[i];
        int nj = j-sell;
        assert(nj >= 0);
        assert(nj < 10000);
        chmax(dp[nj][i+1], nm);
        chmax(maxRest, nm);
      }
    }
  }
  printf("%lld\n", maxRest);
  // rep(i, a) {
  //   rep()
  // }
  return 0;
}