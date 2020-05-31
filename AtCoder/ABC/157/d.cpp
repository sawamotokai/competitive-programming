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

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  // bool is useful for MST 
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  UnionFind uf(n);  
  vi deg(n);
  rep(i,m) {
    int a,b; cin >> a >>b;
    a--; b--;
    uf.unite(a,b);
    deg[a]++;
    deg[b]++;
  }
  vvi to(n);
  rep(i,k) {
    int c,d; cin >> c >> d;
    c--; d--;
    to[c].push_back(d);
    to[d].push_back(c);
  }
  rep(i, n) {
    int ans = uf.size(i) - 1 - deg[i];
    for (int x: to[i]) {
      if (uf.same(x, i)) ans--;
    }
    printf("%d%c", ans, i==n-1?'\n':' ');
  }
  return 0;
}