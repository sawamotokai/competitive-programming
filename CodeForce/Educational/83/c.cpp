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

bool helper(int v, int k, vb &used)
{
  if (v == 0)
    return true;
  float log_kV = log(v) / log(k);
  cout << log_kV << " vs " << floor(log_kV) << endl;

  if (log_kV == floor(log_kV) && !used[floor(log_kV)])
  {
    used[floor(log_kV)] = true;
    return true;
  }
  log_kV = floor(log_kV);
  if (used[log_kV])
    return false;
  used[log_kV] = true;
  return helper(v - pow(k, log_kV), k, used);
}

int main()
{
  int t;
  cin >> t;
  rep(_, t)
  {
    int n, k;
    cin >> n >> k;
    vi v(n, 0);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
      vb used(100, false);
      if (!helper(v[i], k, used))
      {
        ok = false;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}