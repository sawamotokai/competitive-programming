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
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
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
  ll n,m; cin >> n >> m;
  UnionFind uf(n);   
  ll num = (ll) n*(n-1)/2;
  vector<ll> ans;
  vi A(m), B(m);
  rep(i,m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  rep(i,m) {
    ll a = A[i], b=B[i];
    ans.push_back(num);
    if (!uf.same(a,b)) {
      num -= (ll) uf.size(a) * uf.size(b);
    }
    uf.unite(a, b);
  }
  reverse(ans.begin(), ans.end());
  rep(i,m) cout << ans[i] << endl;
  return 0;
}