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

int main()
{
  int n, m;
  map<int, int> mp;
  cin >> n >> m;
  rep(i, m)
  {
    int s, c;
    cin >> s >> c;
    if (mp.find(s) != mp.end() && mp.find(s)->second != c)
    {
      cout << -1 << endl;
      return 0;
    }
    else
      mp[s] = c;
  }

  int ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    if ((n != 1 && it->first == 1 && it->second == 0))
    {
      cout << -1 << endl;
      return 0;
    }
    ans += it->second * pow(10, n - it->first);
    // ans *= pow(10, n - it->first);
  }

  if (ans < pow(10, n - 1))
  {
    if (n != 1)
      ans += pow(10, n - 1);
  }

  cout << ans << endl;
  return 0;
}