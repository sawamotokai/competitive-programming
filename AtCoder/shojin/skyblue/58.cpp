// abc35d
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

struct edge {
  int next;
  ll w;
  edge(int next, ll w):next(next),w(w){}
};

struct Vertex {
  ll val;
  int id;
  Vertex(int id, ll val):id(id), val(val){}
  bool operator<(const Vertex &rhs) const {
    return this->val > rhs.val;
  }
};
vector<edge> to[100005];
vector<edge> to2[100005];
int n,m;

int main() {
  int t; 
  cin >> n >> m >> t;
  vll dp(n, LINF);
  vll dp2(n, LINF);
  vll a(n);
  rep(i,n) cin >> a[i];
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    to[a].emplace_back(b, c);
    to2[b].emplace_back(a,c);
  }
  priority_queue<Vertex> q;
  q.emplace(0, 0);
  dp[0] = 0;
  while(q.size()) {
    Vertex top = q.top(); q.pop();
    int v = top.id;
    if (top.val > dp[v]) continue;
    for (auto next: to[v]) {
      int u = next.next; 
      ll nval = top.val + next.w;
      chmin(dp[u], nval);
      q.emplace(u, nval);
    }
  }
  q.emplace(0, 0);
  dp2[0] = 0;
  while(q.size()) {
    Vertex top = q.top(); q.pop();
    int v = top.id;
    if (top.val > dp2[v]) continue;
    for (auto next: to2[v]) {
      int u = next.next; 
      ll nval = top.val + next.w;
      chmin(dp2[u], nval);
      q.emplace(u, nval);
    }
  }
  ll ans = 0;
  rep(i,n) {
    ll dist = dp[i];
    dist += dp2[i];
    ll rest = max(0LL, t-dist);
    ll num = rest*a[i];
    chmax(ans, num);
  }
  cout << ans << endl;
  return 0;
}