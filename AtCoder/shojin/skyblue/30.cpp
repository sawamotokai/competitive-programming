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


// abc106d
int main() {
  int n, m, q; cin >> n >> m >> q;
  vvi a(n+1, vi(n+1));
  rep(i, m) {
    int l,r; cin >> l >> r;
    a[l][r]++;
  }
  vvi sum(n+1, vi(n+1, 0));
  rep(l, n+1) {
    rep(r, n) {
      sum[l][r+1] += sum[l][r] + a[l][r+1];  
    }
  } 
  // for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + a[i][j];
	// }

  auto solve = [&] {
    int l,r; cin >> l >> r;
    int ans = 0;
    for (int i=l; i<=r; i++) ans += sum[i][r] - sum[i][l-1];
    cout << ans << endl;
  };

  rep(i,q) solve();
  return 0;

}