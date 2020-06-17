#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
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
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
//clang++ -std=c++11 -stdlib=libc++ 

int dp[3005][3005];


int main() {
  int n,t; cin >> n >> t;
  vii p(n);
  rep(i,n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  int ans =0;
  rep(i,n) {
    rep(j, t) {
      chmax(dp[i+1][j], dp[i][j]);
      int nj = j + p[i].first;
      if (nj < t) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + p[i].second);
    }
    int now = dp[i][t-1] + p[i].second;
    chmax(ans, now);
  }
  cout << ans << endl;
  return 0;
}