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

double p[3100];
double dp[3100][3100];
int main()
{
  int n;
  scanf("%d", &n);
  rep(i, n) scanf("%lf", p + i + 1); // p[i] <- ith coin
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    // dp[i][0] = dp[i - 1][0] * (1 - p[i]);
    for (int j = 0; j <= i; j++)
    {
      if (j - 1 >= 0)
        dp[i][j] += dp[i - 1][j - 1] * (p[i]);
      dp[i][j] += dp[i - 1][j] * (1 - p[i]);
      // dp[i][j+1] = dp[i-1][j]
    }
  }
  double ans = 0;
  for (int i = n / 2 + 1; i <= n; i++)
    ans += dp[n][i];
  printf("%.12f\n", ans);
  return 0;
}