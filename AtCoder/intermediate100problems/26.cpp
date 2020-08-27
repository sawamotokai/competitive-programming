#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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

int N,Q;
vi to[200006];
ll add[200005];
ll ans[200005];

void dfs(int v=0, int p=-1, ll now=0) {
  now += add[v];
  ans[v] += now;
  for (int u: to[v]) {
    if (u==p) continue;
    dfs(u, v, now);
  }
}

int main() {
  cin >> N >> Q;
  rep(i,N-1) {
  int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i,Q) {
    int p,x;cin>>p>>x;
    p--;
    add[p]+=x;
  }
  dfs();  
  rep(i,N) printf("%lld%c",ans[i],i==N-1?'\n':' ');
  return 0;
}