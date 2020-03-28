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

int a[1000005];
int main()
{
  int k, n;
  cin >> k >> n;
  rep(i, n) cin >> a[i];
  int ans = 1e9 + 1;
  rep(i, n)
  {
    int cw, ccw;
    if (i)
      cw = k - (a[i] - a[i - 1]);
    else
      cw = k - (a[i] + k - a[n - 1]);
    if (i + 1 == n)
      ccw = k - (a[0] - a[i]);
    else
      ccw = k - (a[i + 1] - a[i]);
    int temp = min(cw, ccw);
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}