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
  int n,m,x; cin >> n >> m>>x;
  vi cost(n);
  vvi a(n, vi(m,0));
  rep(i, n) {
    cin >> cost[i];
    rep(j, m) {
      cin >> a[i][j];
    }
  }
  int ans = INF;
  auto f = [&](vi u) {
    for(int num : u) {
      if (num<x) return false;
    }
    return true;
  };
  for (int i=0; i<(1<<n); i++) {
    int price = 0;
    vi understanding(m,0);
    for (int j=0; j<n; j++) {
      if ((i>>j)&1) {
        price+=cost[j];
        rep(k,m) {
          understanding[k] += a[j][k];
        }
      } 
    }
    if (f(understanding)) ans = min(ans, price);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}