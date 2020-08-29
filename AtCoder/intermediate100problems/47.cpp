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

int N;
ll A[2005];
ll dp[2004][2005];

ll rec(int l, int r, int s) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) {
    if (s) return dp[l][r] = 0;
    return dp[l][r] = A[l];
  }
  if (s) {    
    if (A[l] > A[r]) return dp[l][r] = rec((l+1)%N, r, 0);
    else return dp[l][r] = rec(l, (r-1+N)%N, 0);
  }
  return dp[l][r] = max(rec((l+1)%N, r, 1) + A[l], rec(l, (r-1+N) % N, 1) + A[r]);
}

int main() {
  cin >> N;
  rep(i,N) cin >> A[i];
  memset(dp, -1, sizeof(dp));
  ll ans = 0;
  rep(i,N) {
    chmax(ans, rec((i+1)%N,(i+N-1)%N,1) + A[i]);
  }
  cout << ans << endl;
  return 0;
}