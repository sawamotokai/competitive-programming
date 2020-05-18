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

int main() {
  int n,m; cin >> n >>m;
  vvi to(n, vi());
  rep(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vi from(n, INF);
  queue<int> q;
  q.push(0);
  while(q.size()) {
    int v = q.front(); q.pop();
    for (int u: to[v]) {
      if (u==v) continue;
      if (from[u] == INF) {
        from[u] = v;
        q.push(u);
      }
    }
  }
  for (int i=1; i<n; i++) {
    if (from[i] == INF) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i=1; i<n; i++) {
    cout << from[i] + 1 << endl;
  }
  return 0;
}