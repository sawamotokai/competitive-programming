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

// abc100d

int main() {
  int n,m; cin >> n >> m;
  vll x(n), y(n), z(n);
  rep(i,n) cin >> x[i] >> y[i] >> z[i];
  ll ans =0;
  rep(i, 2) {
    rep(j, 2) {
      rep(k, 2) {
        vll a(n);
        rep(l,n) {
          a[l] += i==0?x[l]:-x[l];
          a[l] += j==0?y[l]:-y[l];
          a[l] += k==0?z[l]:-z[l];
        }
        sort(a.rbegin(), a.rend());
        ll num = 0;
        rep(l,m) num+=a[l];
        chmax(ans, num);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}