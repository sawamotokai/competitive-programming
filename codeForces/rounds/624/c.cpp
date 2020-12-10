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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vi p(m);
    rep(i, m) cin >> p[i];
    map<char, int> mp;
    rep(i, 26)
    {
      mp['a' + i] = 0;
    }
    rep(i, n)
    {
      mp[s[i]]++;
    }
    sort(p.begin(), p.end());
    int last = 0;
    rep(i, m)
    {
      int range = p[i];
      for (int j = last; j < range; j++)
      {
        mp[s[j]] += (m - i);
      }
      last = range;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
      cout << it->second << " ";
    }
    cout << endl;
  }
  return 0;
}