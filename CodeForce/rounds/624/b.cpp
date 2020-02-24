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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi p(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> p[i];
    vi copy(a);
    sort(copy.begin(), copy.end());
    vi copy2(a);
    sort(p.begin(), p.end());
    rep(i, m)
    {
      if (a[p[i] - 1] > a[p[i]])
        swap(a[p[i] - 1], a[p[i]]);
    }
    bool ok = true;
    rep(i, n)
    {
      if (a[i] != copy[i])
        ok = false;
    }
    if (ok)
    {
      cout << "YES" << endl;
      continue;
    }
    ok = true;
    for (int i = m - 1; i >= 0; i--)
    {
      if (a[p[i] - 1] > a[p[i]])
        swap(a[p[i] - 1], a[p[i]]);
    }
    rep(i, n)
    {
      if (a[i] != copy[i])
        ok = false;
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}