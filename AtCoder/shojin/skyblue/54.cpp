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


int n,m; 
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
  cin >> n >> m;
  vector<pair<ii, int>> es(m);
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    es[i] = {ii(a,b), c};
  }
  int q; cin >> q;
  vector<pair<ii, int>> qs(q);
  rep(i,q) {
    cin >> qs[i].first.first >> qs[i].second;
    qs[i].first.second = i;
  }
  sort(es.begin(), es.end(), [](pair<ii,int> a, pair<ii,int> b){return a.second > b.second;});
  sort(qs.begin(), qs.end(), [](pair<ii,int> a, pair<ii,int> b){return a.second > b.second;});
  int eIdx=0;
  UnionFind uf(n);
  vi ans(q);
  rep(i,q) {
    int city = qs[i].first.first; int year = qs[i].second;
    city--;
    while (eIdx < m && es[eIdx].second > year) {
      int c1 = es[eIdx].first.first;
      int c2 = es[eIdx].first.second;
      uf.unite(c1, c2);
      eIdx++;
    }
    int id = qs[i].first.second;
    ans[id] = uf.size(city);
    // cout << uf.size(city) << endl;
  }
  rep(i,q) cout << ans[i] << endl;  
  return 0;
}