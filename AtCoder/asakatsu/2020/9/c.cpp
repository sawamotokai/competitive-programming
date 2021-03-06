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

int main() {
  int n,m,v,p; cin >> n >> m >> v >>p;
  vector<ll> a(n); rep(i,n) cin >> a[i];
  vector<pll> x(n);
  sort(a.begin(), a.end());
  rep(i,n) {
    x[i] = pll(a[i], i);
  }
  rep(i, v) x[i].first += m;
  sort(x.begin(), x.end(), [](pll a, pll b){return a.first>b.first;});
  ll leftMost=1e9;
  rep(i, p) {
    leftMost = min(leftMost, x[i].second);
  } 
  int ans = a.end() - lower_bound(a.begin(), a.end(), a[leftMost]);
  cout << ans << endl; 
  return 0;
}