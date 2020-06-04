#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 
// nomura 2020 c
int main() {
  int n; cin >> n;
  vector<ll> a(n+1);
  cin >> a[0];
  rep(i,n) {
    cin >> a[i+1];
  }  
  vector<pll> range(n+1);
  range[n] = pll(a[n], a[n]); 
  for (int i=n-1; i>=0; i--) {
    ll mx = range[i+1].second + a[i];
    ll mn = ceil(range[i+1].first/(double)2) + a[i];
    range[i] = pll(mn, mx);
  } 
  if (range[0].first > 1) {
    cout << -1 << endl; return 0;
  }
  ll ans = 1;
  ll prevBranch = 1 - a[0];
  for (int i=1; i<=n; i++) {
    ll node = min(2ll * prevBranch, range[i].second);
    ans += node;
    prevBranch = node - a[i];
  }
  printf("%lld\n", ans);
  return 0;
}