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



// dp[l][r] := how many can be hammered out in range [l, r)
int dp[301][301];
int w[301];

int rec(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (abs(l-r) <= 1) return dp[l][r] = 0;
  int ret = 0;
  if (abs(w[l]-w[r-1]) <= 1) {
    if (rec(l+1, r-1) == r-l-2) chmax(ret, r-l);
  }
  rep2(m, l+1, r-1) chmax(ret, rec(l, m) + rec(m, r));
  return dp[l][r] = ret;
}

void solve(int n) {
  rep(i,n) cin >> w[i];
  rep(i,n+1)rep(j,n+1) dp[i][j] = -1;
  cout << rec(0,n) << endl; 
}

int main() {
  while (1) {
    int n; cin >> n;
    if (!n) break;
    solve(n); 
  }
  return 0;
}