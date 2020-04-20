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
  int n,m; cin >> n >> m;
  // vb chosen(m+1, false);
  vi chosen(n+1, 1);
  bitset<100010> dp;
  // chosen[1] = 1;
  dp[1] = true;
  rep(i,m) {
    int x,y; cin >> x >> y;
    if (dp[x]) {
      dp[y] = true;
      if (chosen[x]==1) dp[x] = false;
    }
    chosen[y]++;
    chosen[x]--;
  }
  int ans =0;
  rep(i, n+1) {
    if (chosen[i]>0 && dp[i]) ans++;
  }
  cout << ans << endl;
  return 0;
} 