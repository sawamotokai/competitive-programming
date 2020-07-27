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

int n;
vi to[100005];

int mod = 1e9+7;
ll dp[100004][2];

ll dfs(int v=0, int from=-1, int isBlack=0) {
  if (dp[v][isBlack]) return dp[v][isBlack];
  ll w = 1;
  ll b = 1;
  for (int u: to[v]) {
    if (u == from) continue;
    (b *= dfs(u, v, 1)) %= mod;
    (w *= dfs(u, v, 0)) %= mod;
  }
  ll ret = w;
  if (!isBlack) (ret += b) %= mod;
  return dp[v][isBlack] = ret;
}

int main() {
  cin >> n;
  rep(i,n-1) {
  int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs();
  cout << (dp[0][0] + dp[0][1]) % mod << endl;
  return 0;
}