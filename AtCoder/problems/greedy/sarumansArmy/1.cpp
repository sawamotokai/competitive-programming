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
  ll x, y;
  cin >> x >> y;
  int ans = 1;
  while (x < y)
  {
    x <<= 1;
    if (x <= y)
      ans++;
  }
  std::cout << ans << std::endl;
  return 0;
}