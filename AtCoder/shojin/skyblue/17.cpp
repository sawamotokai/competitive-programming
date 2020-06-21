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

int dp[5005][5005];
// abc141 e
int main() {
  int n; string s; cin >> n >> s;
  int ans = 0;
  for (int i=n-1; i>=0; i--) {
    for (int j=i; j>=0; j--) {
      if (s[i] == s[j]) dp[i][j] = min(i-j, dp[i+1][j+1]+1); 
      else dp[i][j] = 0;
      chmax(ans, dp[i][j]);
    }
  } 
  cout << ans << endl;
  return 0;
}