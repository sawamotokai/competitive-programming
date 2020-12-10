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
  rep(z, t)
  {
    int a, b;
    cin >> a >> b;
    int ret = 0;
    if (a != b)
    {
      if (a < b)
      {
        if ((a - b) & 1)
          ret = 1;
        else
          ret = 2;
      }
      else
      {
        if ((b - a) & 1)
          ret = 2;
        else
          ret = 1;
      }
    }
    std::cout << ret << std::endl;
  }
  return 0;
}