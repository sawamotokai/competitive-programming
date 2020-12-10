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

void solve () {
  int n,x,y;
  cin >>n >> x >> y;
  assert(x < y);
  // if (y-x < n) {
  //   int mn = max(1,y-n+1);
  //   rep(i,n) printf("%d%c", mn++, i==n-1?'\n':' ');
  // } else {
  //   int dif = y-x;
  //   set<int> freq;
  //   for (int i=1; i*i<=n; i++) {
  //     while (dif % i == 0) {
  //       dif /= i;
  //       freq.insert(i);
  //       freq.insert(dif/i);
  //     }
  //   }
  //   for (int num: freq) {
  //     if (x >= y-(n-1)*num && y-(n-1)*num>=1) {
  //       int nm =  
  //       break;
  //     }
  //   }
  //   rep(i,n) printf("%d%c", y-i*dif, i==n-1?'\n':' ');
  // }
  int ans = INF;
  int finalFreq = INF;
  rep(freq, 51) {
    rep(mx, 2501) {
      bool ok = true;
      bool xx = false;
      bool yy = false;
      rep(i,n) {
        int nn = mx - i*freq;
        if (nn == x) xx = true;
        if (nn == y) yy = true;
        if (nn < 1) {
          ok = false;
          break;
        }
      }
      if (ok && xx && yy) if (chmin(ans,mx)) finalFreq = freq;
    }
  }
  rep3(i,n-1, 0) printf("%lld%c", ans-finalFreq*i, i==0?'\n':' ');
}

int t;
int main() {
  cin >> t;
  rep(i,t) solve();
  return 0;
}