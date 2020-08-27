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

int n, q;
int A[21];
int dp[21][2005];

int main() {
  cin >> n;
  rep(i,n) cin >> A[i];
  dp[0][0] = true;
  rep(i,n) {
    int a = A[i];
    rep(j, 2001) {
      if (j-a >= 0) dp[i+1][j] |= dp[i][j-a];
      dp[i+1][j] |= dp[i][j];
    }
  }
  cin >> q;
  while(q--) {
    int m; cin >> m;
    bool ok = dp[n][m];
    ok();
  }
  return 0;
}