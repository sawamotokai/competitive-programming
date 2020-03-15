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

int n;

void dfs(string s, char mx)
{
  if (s.length() == n)
  {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= mx + 1; c++)
  {
    string t = s;
    t += c;
    dfs(t, max(mx, c));
  }
}

int main()
{
  cin >> n;
  dfs("", 'a' - 1);
  return 0;
}