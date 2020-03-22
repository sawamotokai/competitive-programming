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

int dp[3010][3010];

int main()
{
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++)
    for (int j = 0; j < t.length(); j++)
    {
      if (s[i] == t[j])
      {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else
      {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  vector<char> ans;
  int i = s.length(), j = t.length();
  while (i > 0 && j > 0)
  {
    if (s[i - 1] == t[j - 1])
    {
      ans.push_back(s[i - 1]);
      i--;
      j--;
    }
    else
    {
      if (dp[i][j - 1] > dp[i][j])
        j--;
      else
        i--;
    }
  }
  reverse(ans.begin(), ans.end());
  rep(i, ans.size()) cout << ans[i];
  cout << endl;
  return 0;
}