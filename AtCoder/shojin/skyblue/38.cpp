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
// ll x[100010], v[100010];
// ll sumR[100010];
// ll sumL[100010];
// ll maxL[100010];
// ll maxR[100010];
int main() {
  // 095d
  ll n; ll c; cin >> n >> c;
  vll x(n+4,0), v(n+4,0);
  rep(i,n) cin >> x[i+1] >> v[i+1];
  x[n+1] = c; 
  v[n+1] = 0;
  x[0] = v[0] = 0;
  vll maxR(n+4,0), maxL(n+4,0), sumR(n+4,0), sumL(n+4,0);
  rep(i, n+1) {
    sumR[i+1] = sumR[i] + v[i+1]-(x[i+1]-x[i]);
    maxR[i+1] = max(maxR[i], sumR[i+1]);
  }
  for (int i=n; i>=0; i--) {
    sumL[i] = sumL[i+1] + v[i]-(x[i+1]-x[i]);
    maxL[i] = max(maxL[i+1], sumL[i]);
  }
  ll ans = 0;
  for (int i=n+1; i>=0; i--) {
    ll cal = sumL[i] - (c-x[i]);
    if (i) cal += maxR[i-1];
    chmax(ans, cal);
  }
  rep(i, n+1) {
    ll cal = sumR[i] - x[i];
    if (i != n) cal += maxL[i+1];
    chmax(ans, cal);
  } 
  printf("%lld\n", ans);
  return 0;
}