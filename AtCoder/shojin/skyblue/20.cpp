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
// abc125c
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int main() {
// observation lcd(a,b...,z) = a*b..*z/gcd(a,b,..z)
// gcd = prod / lcd

  int n; cin >> n;
  vi a(n); 
  rep(i,n) cin >> a[i];
  vector<ll> lGCD(n), rGCD(n); 
  lGCD[0]=a[0];
  rGCD[n-1]=a.back();
  for (int i=1; i<n;i++) {
    lGCD[i] = gcd(lGCD[i-1], a[i-1]);
  }
  for (int i=n-2; i>=0; i--) {
    rGCD[i] = gcd(rGCD[i+1], a[i+1]);
  }
  lGCD[0] = rGCD[0];
  rGCD[n-1] = lGCD[n-1];
  ll ans = 0;
  rep(i,n) {
    ll now = gcd(lGCD[i], rGCD[i]);
    chmax(ans, now);
  } 
  cout << ans << endl;
  return 0;
}