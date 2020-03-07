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
  int a, b;
  cin >> a >> b;
  int a_l = ceil(a / 0.08);
  int b_l = ceil(b / 0.10);
  float a_h = ((a + 1) / 0.08);
  float b_h = ((b + 1) / 0.10);
  int ans = -1;
  if (a_l >= b_l)
  {
    if (a_l < b_h)
    {
      ans = a_l;
    }
  }
  else
  {
    if (b_l < a_h)
      ans = b_l;
  }
  cout << ans << endl;
  return 0;
}