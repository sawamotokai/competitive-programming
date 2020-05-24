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
int mod = 1e9+7;
ll dp[100005][2];
int main() {
  string s; cin >> s;
  int n = s.length();
  dp[0][1] = 1;
  rep(i,n) {
    // trasition from less than
    (dp[i+1][0] += (dp[i][0]*3)%mod)%=mod;
    // transition from equal
      if (s[i] == '1') {
        // a + b = 0
        (dp[i+1][0] += dp[i][1]) %= mod; 
        // a + b = 1
        (dp[i+1][1] += (dp[i][1] * 2) % mod) %= mod;
      } else {
        // a + b = 0
        (dp[i+1][1] += dp[i][1]) %= mod;
      }
  }
  cout << (dp[n][0]+dp[n][1]) % mod << endl;
  return 0;
}