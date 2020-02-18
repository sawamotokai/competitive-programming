#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef long long ll;
const ll INF = 1e18L + 1;

int main()
{
  string s, t;
  cin >> s >> t;
  vvi dp(s.length() + 1, vector<int>(t.length() + 1, 0));
  // dp[i][j] = max total lenght so far
  rep(i, s.length())
  {
    rep(j, t.length())
    {
      if (s[i] == t[j])
      {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
    }
  }
  int ans = 0;
  rep(i, s.length() + 1) rep(j, t.length() + 1) ans = max(ans, dp[i][j]);
  std::cout << ans << std::endl;
  return 0;
}