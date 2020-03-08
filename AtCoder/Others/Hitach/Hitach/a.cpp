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
  string s;
  cin >> s;
  bool ok = true;
  if (!(s.length() & 1))
  {
    for (int i = 0; i < s.length(); i += 2)
    {
      if (s.substr(i, 2) != "hi")
        ok = false;
    }
  }
  else
    ok = false;
  puts(ok ? "Yes" : "No");
  return 0;
}