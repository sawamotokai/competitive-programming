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
typedef vector<bool> vb;
typedef vector<vb> vvb;
const ll INF = 1e18L + 1;

void dfs(vector<string> &newMap, vvb &visited, int x, int y)
{
  if (visited[x][y])
    return;
  if (newMap[x][y] == 'o')
    visited[x][y] = true;
  else
    return;

  if (x)
    dfs(newMap, visited, x - 1, y);
  if (y)
    dfs(newMap, visited, x, y - 1);
  if (x + 1 < 10)
    dfs(newMap, visited, x + 1, y);
  if (y + 1 < 10)
    dfs(newMap, visited, x, y + 1);
}

int main()
{
  vector<string> MAP(10);
  rep(i, 10) cin >> MAP[i];

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      vector<string> newMap = MAP;
      vvb visited(10, vector<bool>(10, false));
      newMap[i][j] = 'o';
      dfs(newMap, visited, i, j);
      bool ok = true;
      for (int x = 0; x < 10; x++)
        for (int y = 0; y < 10; y++)
          if (newMap[x][y] == 'o' && !visited[x][y])
          {
            ok = false;
          }
      if (ok)
      {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}