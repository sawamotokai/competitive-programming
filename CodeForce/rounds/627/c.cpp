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
    string s;
    cin >> s;
    // longest consecutive L is the mimimum d
    int lenL = 0;
    vi lengthL(s.length(), 0);
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'L')
        if (i)
          lengthL[i] = lengthL[i - 1] + 1;
        else
          lengthL[i] = 1;
      lenL = max(lenL, lengthL[i]);
    }
    cout << lenL + 1 << endl;
  }
  return 0;
}