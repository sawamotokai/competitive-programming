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
  int n,k; cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  rep(i,k) {
    vi b(n+1);
    rep(i,n) {
      int l = max(0, i-a[i]);
      int r = min(n-1, i+a[i]);
      int rc = r+1;
      b[l]++;
      if (rc < n) b[rc]--;
    }
    rep(i, n) b[i+1] += b[i];
    b.pop_back();
    if (a == b) break;
    a = b;
  }
  rep(i,n) printf("%d%c", a[i], i==n-1?'\n':' ');
  return 0;
}