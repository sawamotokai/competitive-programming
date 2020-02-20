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

int p[11];
int c[11];
int main()
{
  int D, G;
  cin >> D >> G;
  rep(i, D) cin >> p[i] >> c[i];

  int ans = 1e9 + 1;

  for (int i = 0; i < (1 << D); i++)
  {
    int goal = G;
    int count = 0;
    vector<bool> used(D, false);
    for (int j = 0; j < D; j++)
    {
      if (i & (1 << j))
      {
        assert(!used[j]);
        used[j] = true;
        goal -= p[j] * (j + 1) * 100;
        goal -= c[j];
        count += p[j];
      }
    }
    if (goal > 0)
    {
      for (int j = D - 1; j >= 0; j--)
      {
        if (!used[j])
        {
          while (goal > 0)
          {
            goal -= (j + 1) * 100;
            count++;
          }
        }
        else
        {
          continue;
        }
        break;
      }
    }
    if (goal <= 0)
      ans = min(ans, count);
  }
  cout << ans << endl;
  return 0;
}