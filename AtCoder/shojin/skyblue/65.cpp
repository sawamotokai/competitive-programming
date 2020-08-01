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
//clang++ -std=c++11 -stdlib=lib

// abc029d

int main() {
  ll N; cin >> N;
  ll ans = 0;
  ll keta = 10;
  rep(i, 11) {
    ans += N/keta * (keta/10);
    ll add = N % keta;
    if (add >= keta/5) ans += keta/10;
    else if (add - keta/10 >= 0) ans += add - keta/10 + 1;
    keta *= 10;
  }
  printf("%lld\n", ans);
  return 0;
}