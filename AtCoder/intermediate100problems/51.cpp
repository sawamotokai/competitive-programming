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

int n;
ll dp[1<<3][1005];
int mod =10007;

int main() {
  cin >> n;
  string s; cin >> s;
  if (s[0] == 'J') {
    dp[4][0] = 1;
    dp[5][0] = 1;
  }
  if (s[0] == 'O') dp[6][0] = 1;
  if (s[0] == 'I') dp[5][0] = 1;
  dp[7][0] = 1;
    
  rep2(i,1,n-1) {
    if (s[i] == 'J') {
      rep(prev, 8) {
        rep(now, 8) {
          if (!(now & (1<<2))) continue;
          if (prev & now) (dp[now][i] += dp[prev][i-1]) %= mod;
        }
      }
    }
    if (s[i] == 'O') {
      rep(prev, 8) {
        rep(now, 8) {
          if (!(now & (1<<1))) continue;
          if (prev & now) (dp[now][i] += dp[prev][i-1])%=mod;
        }
      }
    }
    if (s[i] == 'I') {
      rep(prev, 8) {
        rep(now, 8) {
          if (!(now & (1<<0))) continue;
          if (prev & now) (dp[now][i] += dp[prev][i-1]%=mod);
        }
      }
    }
  }
  ll ans = 0;
  rep(i,8) (ans += dp[i][n-1]) %= mod;
  cout << ans << endl;
  return 0;
}