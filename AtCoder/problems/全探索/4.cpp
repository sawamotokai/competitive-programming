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

int t[5];

int main()
{
  int N;
  scanf("%d", &N);
  rep(i, N) cin >> t[i];
  int ans = 1e9 + 1;

  for (int i = 0; i < (1 << N); i++)
  {
    int a = 0, b = 0;
    for (int j = 0; j < N; j++)
    {
      if (i & (1 << j))
      {
        a += t[j];
      }
      else
      {
        b += t[j];
      }
    }
    ans = min(ans, max(a, b));
  }
  std::cout << ans << std::endl;
  return 0;
}