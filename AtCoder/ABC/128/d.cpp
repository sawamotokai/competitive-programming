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
  int n,k; cin >> n >> k;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  int r = min(n,k);

  ll ans = 0;
  rep(i, r+1) {
    rep(j, r+1) {
      if (i+j > r) continue;
      int t = max(0, k-(i+j));
      priority_queue<ll> pq;
      ll sum = 0;
      rep(a,i) {
        ll nv = v[a];
        sum += nv;
        if (nv < 0) pq.push(-nv);
      }
      for (int a=0; a<j;a++) {
        ll nv = v[n-1-a];
        sum += nv;
        if (nv < 0) pq.push(-nv);
      }
      rep(a,t) {
        if (pq.empty()) break;
        ll nv = pq.top(); pq.pop(); 
        sum += nv;
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}