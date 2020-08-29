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

int q;
int dp[1005][1005];

void solve() {
  memset(dp,0,sizeof(dp));
  string s,t; cin >> s >> t;
  int sl = s.length(), tl = t.length();
  rep(i,sl) {
    rep(j,tl) {
      if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
      chmax(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
    }
  }
  cout << dp[sl][tl] << endl;
}

int main() {
  cin >> q;
  while(q--) solve(); 
  return 0;
}