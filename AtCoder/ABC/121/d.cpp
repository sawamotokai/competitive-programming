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

ll A,B;
int main() {
  cin >> A >> B;
  ll ans = 0;
  auto f = [](ll n) {
    if (n == 0) return 0ll;
    if (n & 1) {
      return ((n+1)/2) & 1;
    } else {
      return (((n+1)/2) & 1) + n;
    }
  };
  ans = f (B) ^ f (A-1);
  printf("%lld\n", ans);
  return 0;
}