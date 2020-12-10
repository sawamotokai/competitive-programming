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
  int n;
  cin >> n;
  vi a(n, 0);
  vi b(n, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  int ans = 0;
  vi diffs(n, 0);
  rep(i, n)
  {
    diffs[i] = a[i] - b[i];
  }
  sort(diffs.begin(), diffs.end());
  for (int i = diffs.size() - 1; i > 0; i--)
  {
    if (diffs[i] <= 0)
      break;
    auto upper = upper_bound(diffs.begin(), diffs.end(), -1 * diffs[i]);
    ans += (diffs.begin() + i - upper);
  }
  cout << ans << endl;
  return 0;
}