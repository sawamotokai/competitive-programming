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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  ll N; cin>>N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  vector<pair<ll,ll>> ord(N);
  rep(i,N) ord[i] = pair<ll,ll>(i, A[i]);
  sort(ord.begin(), ord.end(), [](pair<ll,ll> a, pair<ll,ll> b) {return a.second>b.second;});
  vector<vector<ll>> dp(N+1, vector<ll>(N+1,0)); // total when there's l babies on the left and r on the right

  ll ans = 0;
  rep(l, N) {
    rep(r,N) {
      if (l+r==N) {
        ans = max(ans, dp[l][r]);
        break;
      }
      ll idx = l+r;
      dp[l+1][r] = max(dp[l+1][r], dp[l][r]+ord[idx].second*abs(ord[idx].first-l));
      dp[l][1+r] = max(dp[l][r+1], dp[l][r]+ord[idx].second*abs((N-1-r) - ord[idx].first));
    }
  }
 printf("%lld\n", ans);
  return 0;
}