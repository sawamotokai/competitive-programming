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

int getMin(int j, si &s, int n)
{
  for (int i = j + 1; i <= 2 * n; i++)
  {
    if (s.find(i) == s.end())
    {
      s.insert(i);
      return i;
    }
  }
  return -1;
}

int main()
{
  int t;
  cin >> t;
  rep(z, t)
  {
    int n;

    cin >> n;
    vi b(n);
    int minA = 1e9 + 1;
    si s;
    rep(i, n)
    {
      cin >> b[i];
      s.insert(b[i]);
    }
    vi ans(2 * n + 10);
    rep(i, n)
    {
      ans[2 * i] = b[i];
      ans[2 * i + 1] = getMin(b[i], s, n);
      // cout << b[i] << " " << getMin(b[i], s, n) << " ";
    }
    bool ok = true;
    rep(i, 2 * n)
    {
      if (ans[i] < 0)
      {
        cout << -1;
        ok = false;
      }
    }
    if (ok)
    {
      rep(i, 2 * n)
      {
        cout << ans[i] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}