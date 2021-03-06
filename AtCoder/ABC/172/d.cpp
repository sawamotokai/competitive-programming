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
int sieve[10000005];

int main() {
  int n; cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j+=i) {
      sieve[j]++;
    }
  }  
  ll ans = 0;
  for (int i=1; i<=n; i++) {
    ans += i*sieve[i];
  }
  printf("%lld\n", ans);
  return 0;
}