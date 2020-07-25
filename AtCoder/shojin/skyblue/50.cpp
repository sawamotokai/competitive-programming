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
// //clang++ -std=c++11 -stdlib=libc++ 

vi to[104];
int dp[104][104];
int n,m;

int main() {
  cin >> n >> m;
  vector<pair<ii, int>> edges(m);
  rep(i, n)rep(j, n) {
    dp[i][j] = INF;
    dp[i][i] = 0;
  }
  rep(i,m) {
  int a,b,c; cin >> a >> b >> c; a--; b--;
  dp[a][b] = c;
  dp[b][a] = c;
  to[a].push_back(b);
  to[b].push_back(a);
  edges[i] = {ii(a,b), c};
  }
  rep(k, n) rep(i,n) rep(j,n) chmin(dp[i][j], dp[i][k]+dp[k][j]); 
  vector<bool> used(m, false);
  rep(s, n) {
    rep(i, m) {
      int k = edges[i].first.first;
      int t = edges[i].first.second;
      int e = edges[i].second;
      if (dp[s][k] > dp[s][t]) swap(k,t);
      if (dp[s][t] == dp[s][k] + e) used[i] = true;
    }
  }
  ll ans =0;
  rep(i, m) if (!used[i]) ans++;
  cout<<ans<<endl;
  return 0;
}