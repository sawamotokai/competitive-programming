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
// soundhound2019c
int main() {
  int n,m,d; cin >> n >> m >> d;
  double ans = 0;
  if (d == 0) {
    ans = 1/(double)n * (double)(m-1);
  } else {
    ans = (m-1) * 2*(n-d)/(double)(n*n);
  }
  printf("%.10f\n", ans);
  return 0;
}