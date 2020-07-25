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

int inDegree[110000];
int dist[110000];
vector<int> edges[110000];
bool wasVisited[110000];

void dfs(int a)
{
  assert(!wasVisited[a]);
  wasVisited[a] = true;
  rep(i, edges[a].size())
  {
    int b = edges[a][i];
    dist[b] = max(dist[b], dist[a] + 1);
    inDegree[b]--;
    if (inDegree[b] == 0)
      dfs(b);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    inDegree[b]++;
  }
  for (int i = 1; i <= n; i++)
    if (!wasVisited[i] && inDegree[i] == 0)
      dfs(i);

  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, dist[i]);

  cout << ans << endl;
  return 0;
}