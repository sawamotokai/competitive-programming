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

int denomination[] = {500, 100, 50, 10, 5, 1};
int main()
{
  int n;
  cin >> n;
  int change = 1000 - n;
  int count = 0;
  while (change > 0)
  {
    for (int i = 0; i < 6; i++)
    {
      int coin = denomination[i];
      if (change >= coin)
      {
        change -= coin;
        count++;
        break;
      }
    }
  }
  cout << count << endl;
  return 0;
}