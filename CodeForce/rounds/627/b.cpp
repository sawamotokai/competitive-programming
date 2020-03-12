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
  int t;
  cin >> t;
  rep(_, t)
  {
    int n;
    cin >> n;
    vi a(n, 0);
    rep(i, n) cin >> a[i];
    bool ok = false;
    si seen;
    seen.insert(a[0]);
    for (int i = 1; i < n - 1; i++)
    {
      if (seen.find(a[i + 1]) != seen.end())
      {
        ok = true;
        break;
      }
      else
        seen.insert(a[i]);
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
