#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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

int N;string S;


int LCS(int idx) {
  string s = S.substr(0, idx);
  string t = S.substr(idx);
  vvi dp(N+1, vi(N+1, 0));
  rep(i, s.length())rep(j, t.length()){
    if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
    else {
      chmax(dp[i+1][j], dp[i][j]);
      chmax(dp[i][j+1], dp[i][j]);
    } 
  }
  return dp[s.length()][t.length()];
}

int main() {
  cin >> N >> S;
  int ans = N;
  rep(i,N) {
    int len = LCS(i);
    int num = N - 2*len;
    assert(num >= 0 && num <= N);
    chmin(ans,num);
  }
  cout << ans << endl;
  return 0;
}