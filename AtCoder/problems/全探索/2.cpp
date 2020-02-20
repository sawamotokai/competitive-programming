#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef long long ll;
const ll INF = 1e18L + 1;

int bcd[3];
int main()
{
  int a;
  cin >> a;
  rep(i, 3)
  {
    bcd[2 - i] = a % 10;
    a /= 10;
  }

  for (int i = 0; i < 8; i++)
  {
    int target = a;
    string ans = "";
    ans += to_string(a);

    for (int j = 0; j < 3; j++)
    {
      if (i & (1 << j))
      {
        target += bcd[j];
        ans += "+";
      }
      else
      {
        target -= bcd[j];
        ans += "-";
      }
      ans += to_string(bcd[j]);
    }
    ans += "=7";
    if (target == 7)
    {
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}