#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"yes":"no");
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
using p = pair<ll,ll>;
const ll linf = 1e18l + 1;
const int inf = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<ll> a(n+1), b(m+1);
  rep(i, n) cin >> a[i+1];
  rep(i, n) a[i+1] += a[i];
  rep(i,m) cin >> b[i+1];
  rep(i,m) b[i+1] += b[i];
  // rep(i,a.size()) printf("%lld%c", a[i], i==a.size()-1?'\n':' ');
  // rep(i,b.size()) printf("%lld%c", b[i], i==b.size()-1?'\n':' ');
  int ans = 0;
  rep (i,n+1) {
    if (a[i] > k) break;
    int now = i;
    int rest = k-a[i];
    auto it = lower_bound(b.begin(), b.end(), rest);
    if (it == b.end()) it--;
    if (rest >= *it) now++;
    now += it - b.begin()-1;
    int ad = it - b.begin()-1;
    // cout << ad << endl;
    // cout << *it << endl;
    // if (rest < *it) now--;
    chmax(ans, now);
  }
  cout << ans << endl;

  return 0;
}