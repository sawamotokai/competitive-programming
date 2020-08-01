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
 
int A,B,C; 
double f(double t) {
  double ret = B*sin(C*t*M_PI) + A*t;
  return ret;
}
 
int main() {
  cin >> A >> B >> C;
  double lo = 0.;
  double hi = 1e9 + 1.0;
  double ans = 0;
  double mid = 0;
  while (abs(ans-100.) > 1e-6) {
    mid = (lo+hi)/2.;
    ans = f(mid);
    if (ans == 100) {
      cout << mid << endl;
      return 0;
    }
    if (ans < 100) lo = mid;
    else hi = mid;
  }
  printf("%.11f\n", mid);
  return 0;
}