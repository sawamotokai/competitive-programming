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
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
const ll INF = 1e18L + 1;

int n, x, y;

int main()
{
  cin >> n >> x >> y;
  for (int k = 1; k < n; k++)
  {
    int ans = 0;
    int farthermost = 1e9;
    vb used(n, false);
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < k; j++)
      {
        if (!used[i + 1])
        {
          ans++;
          farthermost = i + 1;
          used[i + 1] = true;
        }
        if (i == x && !used[y])
        {
          ans++;
          used[y] = true;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}