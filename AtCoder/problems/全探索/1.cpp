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

int main()
{
  string s;
  cin >> s;

  int pos = s.length() - 1;
  ll ans = 0;

  for (int i = 0; i < (1 << pos); i++)
  {
    ll target = stol(s);
    int temp = 0;
    int digits = 0;
    for (int j = 0; j < pos; j++)
    {
      digits++;
      if (i & (1 << j))
      {
        int divisor = pow(10, digits);
        ans += (target % divisor);
        target /= divisor;
        digits = 0;
      }
    }
    ans += target;
  }
  cout << ans << endl;
  return 0;
}