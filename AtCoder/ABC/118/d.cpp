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

int N,M;
int dp[10005];
int num[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
int main() {
  cin >> N >> M;
  vi A(N);
  rep(i,N) cin>>A[i];
  sort(A.rbegin(), A.rend());
  rep(i,N+4) dp[i] = -INF;
  dp[0] = 0;
  auto f = [&] (int n, int a) {
    int nx = n - num[a];
    if (nx < 0) return ;
    chmax(dp[n], dp[nx]+1);
  };
  rep(i,N+1) rep(j,N) f(i, A[i]);
  rep(i,N+1) rep(j,N) {
    if (i-num[A[i]] >= 0 && dp[i-num[A[i]]] == dp[i]-1) cout << A[i];
  }
  cout << endl;
  return 0;
}