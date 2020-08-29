#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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

int N,W;
int v[104],w[104];
int dp[10005];
int main() {
  cin >> N >> W;
  rep(i,N) cin >> v[i] >> w[i];
  rep(i,N) {
    rep3(j,W,0) {
      if (j-w[i] >= 0) chmax(dp[j], dp[j-w[i]] + v[i]);
      chmax(dp[j], dp[j]);
    }
  } 
  int ans = 0;
  rep(i,W+1) chmax(ans, dp[i]);
  cout << ans << endl;
  return 0;
}