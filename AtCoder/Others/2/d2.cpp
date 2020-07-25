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
  int n; cin >> n;
  vi a(n);
  rep(i,n ) cin >> a[i];
  set<int> tani, yama;
  if (a[0] < a[1]) tani.insert(0);
  if (a[n-1] > a[n-2]) yama.insert(n-1);
  for (int i=1; i<n-1; i++) {
    if (a[i] <= a[1+i] && a[i] <= a[i-1] && (a[i+1] != a[i] || a[i] != a[i-1])) tani.insert(i);
    if (a[i] >= a[i+1] && a[i] >= a[i-1]&& (a[i+1] != a[i] || a[i] != a[i-1])) yama.insert(i);
  }
  ll ans = 1000;
  ll rest = 1000;
  ll stock = 0;
  rep(i,n) {
    if (tani.find(i) != tani.end()) {
      ll maxBuy = rest / a[i];
      rest -= maxBuy * a[i];
      stock += maxBuy;
    } 
    if (yama.find(i) != yama.end()) {
      rest += stock * a[i];
      stock = 0;
      chmax(ans, rest);
    }
  }
  printf("%lld\n", ans);
  return 0;
}