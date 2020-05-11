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


int N,M; ll S;
ll MAX_S = 2505;
struct edge {
  int to;
  ll cost, t;
  edge(int to, ll cost, ll t):to(to), cost(cost), t(t) {}
};

struct Data {
  int v; ll s;
  ll x;
  Data(int v, ll s, ll x): v(v), s(s), x(x) {}
  bool operator<(const Data& a) const {
    return  x > a.x;
  }
};

int main() {  
  cin >> N>>M>>S;
  vector<ll> c(N);
  vector<ll> d(N);
  vector<vector<edge>> g(N, vector<edge>());
  rep(i,M) {
    int u,v; ll a,b; cin>>u>>v>>a>>b;
    u--;v--;
    g[u].emplace_back(v,a,b);
    g[v].emplace_back(u,a,b);
          // g[u].push_back(edge{v,a,b});
          // g[v].push_back(edge{u,a,b});
  } 
  
  rep(i, N) {
    cin >> c[i] >> d[i];
  }
  S = min(S, MAX_S);
  priority_queue<Data> q;
  vector<vector<ll>> dp(N, vector<ll>(MAX_S+5, LINF));
  auto push = [&] (int v, ll s, ll x) {
    if (s<0) return;
    // if (s>MAX_S) return ;
    if (dp[v][s] <= x) return ;
    dp[v][s] = x;
    // Data foo = Data(v,s,x);
    // q.push(Data{v,s,x});
    q.emplace(v,s,x);
    // q.push(foo);
  };
  push(0,S,0);
  while(q.size()) {
    Data foo = q.top(); q.pop();
    int v = foo.v;
    S=foo.s;
    ll x = foo.x;
    if (dp[v][S] != x) continue;
    ll ns =  min(S+c[v], MAX_S);
    push(v, ns , x+d[v]);
    rep(i, g[v].size()) {
      edge e = g[v][i];
      int nv = e.to;
      push(nv, S-e.cost, x+e.t);
    }
  }
  for (int i=1; i<dp.size();i++) {
    ll ans = LINF;
    rep(j, dp[i].size()) {
      ans = min(ans, dp[i][j]);
    }
    cout << ans << endl;
  }
  return 0;
}