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
  int N,M; cin>>N>>M;
  vii keys(M);
  rep(i,M) {
    int a,b; cin>>a>>b;
    int s=0;
    rep(i,b) {
      int t; cin >> t;
      s |= (1<<(t-1));
    }
    keys[i]=ii(s,a);
  }
  vi dp(1<<N, INF);
  dp[0] = 0;
  rep(i, 1<<N) {
    rep(j, M) {
      int t = i | keys[j].first;
      int cost = dp[i]+keys[j].second;
      dp[t] = min(dp[t], cost);
    }
  }
  int ans = 0;
  if (dp.back() == INF) {
    ans = -1;
  } else {
    ans = dp.back();
  }
  cout << ans<< endl;
  return 0;
}