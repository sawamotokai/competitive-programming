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
  ll n,k; cin >> n >> k;
  vector<ll> a(n), f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());

  ll l = -1;
  ll r = 1e12;
  ll ans = 0;
  while (l+1<r) {
    ll x = (l+r)/2;
    bool ok = [&] {
      ll sum = 0;
      rep(i, n)
      {
        sum += max(0LL, a[i] - (ll)x / f[i]);
      }
      return sum <= k;
    }();
    if (ok) r = x;
    else l = x;
  }
  cout << r << endl;
  return 0;
}