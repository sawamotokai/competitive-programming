#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
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

int main() {
  int N; cin >> N;
  vll A(N);
  rep(i,N) cin >> A[i];
  ll sum = 0;
  ll mn=LINF;
  rep(i, N) {
    sum += abs(A[i]);
    chmin(mn, abs(A[i]));
  }
  rep(i,N-1) {
    if (A[i] < 0) {
      A[i] *= -1;
      A[i+1] *= -1;
    }
  }
  if (A[N-1] < 0) {
    sum-=2*abs(mn);
  }
  printf("%lld\n", sum);
  return 0;
}
