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

int W[110];
int V[110];

int main()
{
  int n, w;
  cin >> n >> w;
  for (int i = 1; i <= n; i++)
  {
    cin >> W[i] >> V[i];
  }
  ll sumVal = 0;
  rep(i, n + 1) sumVal += V[i];
  vector<ll> dp(sumVal + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = sumVal; j - V[i] >= 0; j--)
    {
      dp[j] = min(dp[j], dp[j - V[i]] + W[i]);
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= sumVal; i++)
    if (dp[i] <= w)
    {
      ans = max(ans, i);
    }
  std::cout << ans << std::endl;
  return 0;
}