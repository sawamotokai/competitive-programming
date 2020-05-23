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
int dp[100005][100005];
int main() {
  string s; cin >> s;
  int n = s.length();
  dp[0][0] = 1;
  rep(i,n) {
    rep(j,2) {
      if (s[i] == '1') {
        // a + b = 0
        {
          dp[i+1][0] = (dp[i][0] + dp[i][1]) % mod;
        }
        // a + b = 1
        dp[i+1][0] = dp[i][0]*2 % mod;
        dp[i+1][1] =
      }
    }
  }
  return 0;
}