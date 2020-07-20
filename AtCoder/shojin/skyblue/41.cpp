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


vi to[100005];

map<P,ll> dist;

int main() {
  int n,m; cin >> n >> m;
  bool ok = true;
  rep(i, m) {
    ll L,R,D; cin >> L >> R >> D;
    --L, --R;
    to[L].push_back(R);
    to[R].push_back(L);
    dist[P(L,R)] = D;
    dist[P(R,L)] = -D;
  }
  vi x(n, INF);
  rep(v, n) {
    if (x[v] == INF) x[v] = 0;
    for (int u: to[v]) {
      ll D = dist[P(v,u)];
      if (x[u] == INF) x[u] = x[v] + D;
      else {
        if (x[u] - x[v] != D) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  puts("Yes");
  return 0;
}