#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

const int mod = 1e9+7;
int main() {
  string s; cin >> s;
  int n = s.length();
  vvi dp(n+1, vi(13, 0));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 13) {
      if (s[i]== '?') {
        rep(k,10) {
          dp[i+1][(j*10 + k) % 13] += dp[i][j];
          dp[i+1][(j*10 + k) % 13] %= mod;
        } 
      } else {
        int d = s[i] - '0';
        dp[i+1][(j*10 +d ) % 13] += dp[i][j];
        dp[i+1][(j*10 + d) % 13] %= mod;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}