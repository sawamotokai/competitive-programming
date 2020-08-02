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
  vii a(n); 
  vi v(n), c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];

  rep(i,n){
    a[i].first = v[i];
    a[i].second = c[i];
  }
  sort(a.begin(), a.end(), [](ii a, ii b) {return a.first - a.second > b.first - b.second;});
  int ans = 0;
  rep(i,n) {
    if (a[i].first - a[i].second < 0) continue;
    ans += a[i].first - a[i].second;
  }
  cout << ans << endl;
  return 0;
}