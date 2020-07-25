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

  vector<ll> dp(w + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    for (int j = w; j - W[i] >= 0; j--)
    {
      dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
    }
  }
  ll ans = 0;
  rep(j, w + 1) ans = max(ans, dp[j]);
  cout << ans << endl;
  return 0;
}