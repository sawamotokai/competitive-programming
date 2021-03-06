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

int V,E;
int dist[20][20];
int dp[1<<20][20];


int main() {
  cin >> V >> E;
  rep(i,20) rep(j,20) dist[i][j] = INF;
  rep(i,E) {
    int a,b,c; cin >> a >> b >> c;
    dist[a][b] =c;
  }
  rep(i,1<<20) rep(j,20) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(bits, 1 << V) {
      rep(v, V) {
        if ((bits & (1 << v))) continue; // if from node is already visited
        rep(u, V) {
          chmin(dp[bits | (1 << v)][v], dp[bits][u] + dist[u][v]);
        }
      }
  }
  ll ans = dp[(1<<V)-1][0];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}