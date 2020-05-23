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


vector<int> to[204];
int main() {
  int N,M,Q; cin >>N>>M>>Q;
  rep(i, M) {
    int u,v; cin >> u >> v;
    u--; v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  vi color(N);
  rep(i,N) cin >> color[i];
  rep(_, Q) {
    int foo; cin >> foo;
    if (foo == 1) {
      int x; cin >> x;
      x--;
      cout << color[x] << endl;
      for (int u: to[x]) {
        color[u] = color[x];   
      }
    } else {
      int x,y; cin >> x >> y;
      x--; 
      cout << color[x] << endl;
      color[x] = y;
    }
  }
  return 0 ;
}