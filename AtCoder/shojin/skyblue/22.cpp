#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
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
  int x,y,z,k; cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i,x) {
    cin >> a[i];
  }
  rep(i,y) {
    cin >> b[i];
  }
  rep(i,z) {
    cin >> c[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  vector<ll> ab, abc;
  rep(i,x) {
    rep(j,y) {
      ab.push_back(a[i] + b[j]);
    }
  }
  sort(ab.rbegin(), ab.rend());
  int n = min(k, (int) ab.size());
  rep(i, n) {
    rep(j, z) {
      abc.push_back(ab[i]+c[j]);
    }
  }
  sort(abc.rbegin(), abc.rend());
  int nn = min(k, (int) abc.size());
  rep(i,nn ) {
    printf("%lld\n", abc[i]);
  }
  return 0;
}