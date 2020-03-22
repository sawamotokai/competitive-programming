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
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
const ll INF = 1e18L + 1;

bool pali(string s)
{
  int l = 0, h = s.length() - 1;
  while (l < h)
  {
    if (s[l] != s[h])
      return false;
    l++;
    h--;
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  bool ok = true;
  string a = s.substr(0, (n - 1) / 2);
  string b = s.substr(((n + 3) / 2) - 1);
  if (!pali(s) || !pali(a) || !pali(b))
    ok = false;
  puts(ok ? "Yes" : "No");
  return 0;
}