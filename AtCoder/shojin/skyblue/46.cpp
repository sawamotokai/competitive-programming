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
  ll n; cin >> n;
  vll a(50, n/50);
  rep(i, 50) a[i]+=i;
  int rest = n%50;
  rep(i,rest) {
    a[i]+=50;
    rep(j,50) {
      if (j==i)continue;
      a[j]--;
    }
  }
  cout << 50 << endl;
  rep(i, 50) {
    printf("%lld%c", a[i], i==49?'\n':' ');
  }
  return 0;
}