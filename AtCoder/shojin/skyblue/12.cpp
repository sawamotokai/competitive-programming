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

//clang++ -std=c++11 -stdlib=libc++ 

int dp[3005][6005];

void takeMax(int &a, int &b) {
  a = max(a, b);
}

int main() {
  int n,t; cin >> n >> t;
  vi a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  rep(i,n) {
    rep(j, t+3001) {
      if (j-a[i] >= t) continue;
      if (j-a[i] >= 0 ) dp[i+1][j] = max(dp[i][j], dp[i][j-a[i]] + b[i]);
      else dp[i+1][j] = dp[i][j];
    }
  }
  int ans = 0;
  rep(i, t+3001) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}