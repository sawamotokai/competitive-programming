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
  rep(i, t)
  {
    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;
    int firstStop = s.length() - 1;
    int j = s.length() - 2;
    while (p > 0 && j >= 0)
    {
      if (j)
      {
        if (s[j] != s[j - 1])
        {
          p -= s[j] == 'A' ? a : b;
          if (p >= 0)
          {
            firstStop = j;
          }
        }
      }
      else
      {
        p -= s[j] == 'A' ? a : b;
        if (p >= 0)
        {
          firstStop = j;
        }
      }

      j--;
    }
    // int walk = s.length() - firstStop + 1;
    cout << 1 + firstStop << endl;
  }
  return 0;
}