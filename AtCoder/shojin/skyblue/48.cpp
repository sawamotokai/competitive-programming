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
  int n; cin >> n;
  vi a(n);
  rep(i,n) cin>>a[i];
  ll ans = LINF;
  
  // even is positive
  // odd is nevgative
  ll sum=0;
  ll num=0;
  rep(i,n) {
    sum+=a[i];
    if (i&1) {
      if (sum>=0) {
        num += (sum + 1);
        sum = -1;
      }
    } else {
      if (sum <= 0) {
        num += (-sum + 1);
        sum = 1;
      }
    }
  }
  chmin(ans, num);
  // even is negative
  // odd is positive
  num = 0;
  sum = 0;
  rep(i,n) {
    sum+=a[i];
    if (i&1) {
      if (sum <= 0) {
        num += (-sum + 1);
        sum = 1;
      }
    } else {
      if (sum>=0) {
        num += (sum + 1);
        sum = -1;
      }
    }
  }
  chmin(ans, num);
  printf("%lld\n", ans);
  return 0;
}