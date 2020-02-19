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

double dp[310][310][310];
int nums[4];
int N;

double rec(int a, int b, int c)
{
  if (a + b + c == 0)
    return 0.0;
  if (dp[a][b][c] >= 0)
    return dp[a][b][c];
  double res = 0.0;
  if (a > 0)
    res += rec(a - 1, b, c) * a;
  if (b > 0)
    res += rec(a + 1, b - 1, c) * b;
  if (c > 0)
    res += rec(a, b + 1, c - 1) * c;
  res += N;
  res /= (a + b + c);
  return dp[a][b][c] = res;
}

int main()
{
  scanf("%d", &N);
  rep(i, N)
  {
    int a;
    scanf("%d", &a);
    nums[a]++;
  }
  memset(dp, -1, sizeof(dp));

  double ans = rec(nums[1], nums[2], nums[3]);
  printf("%.13f\n", ans);
  return 0;
}