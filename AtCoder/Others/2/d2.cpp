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
  ll stock = 0;
  ll money = 1000;
  ll ans = 1000;
  rep(i,n-1) {
    if (a[i] < a[i+1])  {
      ll maxBuy = money / a[i];
      stock += maxBuy;
      money -= maxBuy * a[i];
    } 
    if (a[i] > a[i+1]) {
      money += stock * a[i];
      stock = 0;
      chmax(ans, money);
    }
  }
  money += stock * a[n-1];
  chmax(ans, money);
  printf("%lld\n", ans);
  return 0;
}