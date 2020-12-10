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

vi helper(string s, int n)
{
  int mx = 0;
  char c = s[0];
  rep(i, n) if (s[i] < c)
  {
    mx = i;
    c = s[i];
  }
  vi ans;
  rep(i, n)
  {
    if (s[i] == c)
      ans.push_back(i);
  }
  return ans;
}

pair<string, int> findSmallest(vector<string> strs)
{
  string sm = strs[0];
  int idx = 0;
  for (int i = 1; i < strs.size(); ++i)
    if (sm > strs[i])
    {
      sm = strs[i];
      idx = i;
    }
  return make_pair(sm, idx);
}

string rev(const string str, int k)
{
  string s = str;
  for (int i = 0; i + k < s.length(); i++)
  {
    reverse(s.begin() + i, s.begin() + i + k);
  }
  return s;
}

int main()
{
  int t;
  cin >> t;
  rep(_, t)
  {
    int n;
    string s;
    cin >> n >> s;
    vi cands = helper(s, n);
    vector<string> strs;
    rep(i, cands.size()) strs.push_back(rev(s, cands[i]));
    pair<string, int> ans = findSmallest(strs);
    cout << ans.first << endl
         << ans.second << endl;
  }
  return 0;
}