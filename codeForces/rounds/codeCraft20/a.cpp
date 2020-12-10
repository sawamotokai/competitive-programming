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
    vi score(n);
    rep(i, n)
    {
      cin >> score[i];
    }
    ll sum = 0;
    for (int i = 1; i < n; i++)
      sum += score[i];
    int up = sum;
    int ans = score[0] + up;
    ans = min(ans, m);
    cout
        << ans << endl;
  }
  return 0;
}