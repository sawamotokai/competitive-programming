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

int main() {
  int N,M; cin >> N>>M;
  vii R(M);
  rep(i,M)cin >> R[i].first >> R[i].second;
  vi coverage(N+5);
  rep(i,M) {
    int s = R[i].first;
    int t = R[i].second;
    coverage[s]++, coverage[t+1]--;
  }
  rep(i,N+1) coverage[i+1] += coverage[i];
  vi X(N+5);
  rep(i, N+1) if (coverage[i] == 1) X[i] = 1; else X[i] = 0;
  rep(i, N+1) X[i+1] += X[i];
  // rep(i, N+1) printf("%d%c", coverage[i], i==N?'\n':' ');
  // rep(i, N+1) printf("%d%c", X[i], i==N?'\n':' ');
  vi ans;
  rep(i,M) {
    int s = R[i].first;
    int t = R[i].second;
    int num = X[t] - X[s-1];
    if (num == 0) ans.push_back(i+1);
  }
  cout << ans.size() << endl;
  rep(i,ans.size()) cout << ans[i] << endl;
  return 0;
}