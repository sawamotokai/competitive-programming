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

vi to[200005];
ll ans[200005];

void dfs(int u=0, int k=-1) {
  for (int v: to[u]) {
    if (v == k) continue;
    ans[v] += ans[u];
    dfs(v, u);
  }
}
int main() {
  int n,q; cin >> n >> q;
  rep(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i,q) {
    int p,x; cin >> p >> x;
    p--; ans[p]+=x;
  }
  dfs();
  rep(i,n) printf("%lld%c", ans[i], i==n-1?'\n':' ');
  return 0;
}