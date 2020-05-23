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
int main() {

  int n,m; cin >> n>>m;
  vector<ll> dp(n+1);
  vector<ll> a(n); rep(i,m){
    cin >> a[i];
  }
  dp[0]=1;
  int foo=0;
  for(int i=1; i<=n; i++) {
    if(foo < m && a[foo] == i) {
      dp[i] = 0;
      foo++;
    }
    else {
      if (i<2) dp[i] = 1;
      else dp[i] = (dp[i-1] % mod +dp[i-2] % mod)%mod;
    }
  }
  cout << dp[n] << endl; 
  return 0;
}