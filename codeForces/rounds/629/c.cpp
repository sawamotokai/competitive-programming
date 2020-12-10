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

void solve()
{
  int n;
  string x;
  cin >> n >> x;
  string l, h;
  bool tie = true;
  int idx = 0;
  while (idx < n && tie)
  {
    if (x[idx] == '0')
    {
      l += '0';
      h += '0';
    }
    else if (x[idx] == '1')
    {
      l += '1';
      h += '0';
      tie = false;
    }
    else
    {
      l += '1';
      h += '1';
    }
    idx++;
  }
  for (int i = idx; i < n; i++)
  {
    if (x[i] == '0')
    {
      l += '0';
      h += '0';
    }
    else if (x[i] == '1')
    {
      l += '0';
      h += '1';
    }
    else
    {
      l += '0';
      h += '2';
    }
  }
  std::cout << l << std::endl;
  std::cout << h << std::endl;
}

int main()
{
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}