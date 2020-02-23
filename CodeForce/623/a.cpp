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

int maxVec(vi &v)
{
  int mx = v[0];
  rep(i, v.size()) mx = max(mx, v[i]);
  return mx;
}

int main()
{
  int t;
  cin >> t;
  rep(i, t)
  {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    // x++, y++;
    vi v(4);
    v[0] = (a - x - 1) * b;
    v[1] = x * b;
    v[2] = a * y;
    v[3] = a * (b - y - 1);

    cout << maxVec(v) << endl;
    }
  return 0;
}