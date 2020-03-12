#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
typedef long long ll;
const ll INF = 1e18L + 1;

int main()
{
  int n, h, l;
  cin >> n >> h >> l;
  vi a(n, 0);
  rep(i, n) cin >> a[i];
  // dp[i][j] := if its good when we wake up on ith day at j hours.
  vvi dp(n, vi(h, 0));
  int prev = 0;
  int ans = 0;
  rep(i, n)
  {
    int hour = (prev + a[i]) % h;
    if (l <= hour && hour <= h)
      dp[i + 1][hour] = dp[i][prev] + 1;
    if (l <= hour - 1 && hour - 1 <= h)
      dp[i + 1][hour - 1] = dp[i][prev] + 1;
    if (i)
    {
      if (l <= hour && hour <= h)
        dp[i + 1][hour] = dp[i][prev - 1] + 1;
      if (l <= hour - 1 && hour - 1 <= h)
        dp[i + 1][hour - 1] = dp[i][prev - 1] + 1;
    }
    ans = max(ans, dp[i][prev]);
    ans = max(ans, dp[i][prev - 1]);
    prev = hour;
  }
  cout << ans << endl;
  return 0;
}