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

char grid[1100][1100];
int dp[1100][1100];

const int mod = 1e9 + 7;

int main()
{
  int h, w;
  cin >> h >> w;
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> grid[i][j];
    }
  }
  rep(i, w)
  {
    if (grid[0][i] == '.')
      dp[0][i] = 1;
    else
      break;
  }
  rep(i, h)
  {
    if (grid[i][0] == '.')
      dp[i][0] = 1;
    else
      break;
  }

  for (int i = 1; i < h; i++)
  {
    for (int j = 1; j < w; j++)
    {
      if (grid[i][j] == '.')
      {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        if (dp[i][j] >= mod)
          dp[i][j] -= mod;
      }
    }
  }
  int ans = (dp[h - 1][w - 1]);
  cout << ans << endl;
  return 0;
}