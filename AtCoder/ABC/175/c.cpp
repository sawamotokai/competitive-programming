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

ll X,K,D;
int main() {
  cin >> X>> K >>D;
  ll move = abs(X/D);
  chmin(move, K);
  K -= move;
  if (K == 0) {
    ll ans = abs(X) - D*move;
    printf("%lld\n", ans);
    return 0;
  }
  ll now = abs(X) - D*move;
  if (K&1)  {
    now = abs(now - D);
  }
  printf("%lld\n", now);
  return 0;
}