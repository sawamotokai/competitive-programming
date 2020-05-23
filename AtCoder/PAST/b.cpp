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
  int n,m,q; cin >> n >> m>>q;
  vi solved(m,n);
  vvb prob(n, vb(m, false));
  rep(_,q) {
    int c; cin >> c;
    if (c == 1 ) {
       int a; cin >> a;
       a--;
       ll ans = 0;
       rep(i,m) {
         if (prob[a][i]) ans += solved[i];
       }
       cout << ans << endl;
    } else {
      int a,b; cin >> a>>b;
      a--; b--;
      prob[a][b] = true;
      solved[b]--;
    }
  }
  return 0;
}