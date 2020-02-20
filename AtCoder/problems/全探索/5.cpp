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

bool relation[15][15];

int main()
{
  int N, M;
  cin >> N >> M;
  rep(i, M)
  {
    int x, y;
    cin >> x >> y;
    relation[x][y] = true;
    relation[y][x] = true;
  }
  int ans = 0;
  for (int i = 0; i < (1 << N); i++)
  {
    bool ok = true;
    for (int j = 0; j < N; j++)
    {
      if (i & (1 << j))
      {
        for (int k = j + 1; k < N; k++)
        {
          if (i & (1 << k) && !relation[j][k])
          {
            ok = false;
          }
        }
      }
    }
    int count = 0;
    if (ok)
    {
      for (int j = 0; j < N; j++)
      {
        if (i & (1 << j))
          count++;
      }
      ans = max(ans, count);
    }
  }
  cout << ans << endl;
  return 0;
}