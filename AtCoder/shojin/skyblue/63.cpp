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
  // input
  int n; cin >> n;
  vi x(n), y(n), c(n);
  rep(i,n) cin >> x[i] >> y[i] >> c[i];

  auto findX = [&](double t) {
    double lo = -1e9, hi = 1e9;
    rep(i,n) {
      double range = t / (double) c[i];
      double nl = x[i] - range;
      double nh = x[i] + range;
      chmin(hi, nh);
      chmax(lo, nl);
    }
    if (lo <= hi) return true;
    else return false;
  };
  auto findY = [&](double t) {
    double lo = -1e9, hi = 1e9;
    rep(i,n) {
      double range = t / (double) c[i];
      double nl = y[i] - range;
      double nh = y[i] + range;
      chmin(hi, nh);
      chmax(lo, nl);
    }
    if (lo <= hi) return true;
    else return false;
  };
  // find min t for x    
  double minX = 1e9;
  double hi = 1e9;
  double lo = -1;

  rep(i,100) {
    double mid = (hi+lo)/2.0;
    if (findX(mid)) hi = mid;
    else lo = mid;
    minX = mid;
  }
  // find min t for y

  double minY = 1e9;
  hi = 1e9;
  lo = -1.0;

  rep(i,100) {
    double mid = (hi+lo)/2.0;
    if (findY(mid)) hi = mid;
    else lo = mid;
    minY = mid;
  }

  // find grand max
  double ans = max(minX, minY);
  printf("%.12f\n", ans);
  return 0;
}