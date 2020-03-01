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

int A[55];
int B[55];
int dp[10005][55][55];

int main()
{
  int w, n, K;
  cin >> w >> n >> K;
  rep(i, n)
  {
    cin >> A[i] >> B[i];
  }
  int ans = 0;
  rep(i, w) rep(j, n) for (int k = 1; k < K; k++)
  {
    if (i - A[k - 1] >= 0)
      dp[i][j][k] = max(dp[i][j][k - 1], dp[i - A[k - 1]][j - 1][k - 1] + B[k - 1]);
    ans = max(ans, dp[i][j][k]);
  }
  cout << ans << endl;
  return 0;
}