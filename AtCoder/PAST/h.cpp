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
  int N,L;
  cin >> N >> L;
  vb hurdle(L, false);
  vi x(N); rep(i,N) {
    cin >> x[i];
    hurdle[x[i]] = true;
  }
  ll t1, t2, t3; cin >> t1 >> t2 >> t3;
  vector<ll> dp(L+4,LINF);
  dp[0] = 0;
  rep(i, L) {
    if (hurdle[i]) {
      dp[i + 1] = min(dp[i] + t1 + t3, dp[i + 1]);
      dp[i + 2] = min(dp[i + 2], dp[i] + t2 + t1 + t3);
      dp[i + 4] = min(dp[i + 4], dp[i] + 3 * t2 + t1 +t3);
    }
    else {
      dp[i + 1] = min(dp[i + 1], t1 + dp[i]);
      dp[i + 2] = min(dp[i + 2], dp[i] + t2 + t1);
      dp[i + 4] = min(dp[i + 4], dp[i] + 3 * t2 + t1);
    }
  }
  ll ans = dp[L];
  ll ans2 = dp[L+1] - 0.5*t1 - 0.5*t2;
  ans = min(ans, ans2);
  ans2 = dp[L+2] - 0.5*t1 - 1.5*t2;
  ans = min(ans, ans2);
  ans2 = dp[L+3] - 0.5*t1 - 2.5*t2;
  ans = min(ans, ans2);
  cout << ans << endl;
  return 0;
}