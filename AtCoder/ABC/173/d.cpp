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
  int n;cin>>n;
  vll a(n); rep(i,n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  ll ans = a[0];
  int ptr = 1;
  int cnt = 0;
  rep(i, n-2) {
    ans += a[ptr];
    cnt ^= 1; 
    if (cnt == 0) ptr++;
  }
  printf("%lld\n", ans);
  return 0;
}