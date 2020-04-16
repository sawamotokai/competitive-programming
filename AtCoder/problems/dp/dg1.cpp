#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 
ll banned(ll a) {
  // returns num of banned numbers <= a
  int keta = 1+floor(log10(a));
  vector<vector<vector<ll> > > dp(keta+1, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;
  vi n;
  while(a) {
    n.push_back(a%10);
    a/=10;
  }
  reverse(n.begin(), n.end());
  rep(i, keta) {
    rep(smaller, 2) {
      rep(j, 2) {
        for(int x=0; x<=(smaller? 9 : n[i]); x++) {
          dp[i+1][smaller||x<n[i]][j||x==4||x==9] += dp[i][smaller][j];
        }
      }
    }
  }
  return dp[keta][0][1]+dp[keta][1][1];
}

int main() {
  ll A,B; cin>>A>>B;
  ll isABanned = 0;
  ll b = B;
  while (b) {
    if (b%10==4 || b%10==9) isABanned=1;
    b/=10;
  }
  cout<< banned(B)-banned(A) + isABanned <<endl;
  return 0;
}