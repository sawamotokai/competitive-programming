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
  double p; cin >> p;
  if (p<1.5) {
    printf("%.10f\n", p);
    return 0;
  }
  double x = log2(p*log(2)) - log2(1.5);
  if (x < 0) x = 0;
  double ans = p * pow(0.5, x) + 1.5 * x;
  printf("%.10f\n", ans);
  return 0;
}