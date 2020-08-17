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

int N,M,C;
int B[22];
int A[22][22];
int main() {
  cin >> N >> M >> C;
  rep(i,M)cin>>B[i];
  rep(i,N) rep(j,M) cin >> A[i][j];
  int ans = 0;
  rep(i,N) {
    int sum = 0;
    rep(j,M) {
      sum += A[i][j] * B[j];
    }
    sum += C;
    if (sum > 0) ans ++;
  }
  cout << ans <<endl;
  return 0;
}