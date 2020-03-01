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

int a[3][3];
int B[11];
bool isCalled[110];

int main()
{
  rep(i, 3) rep(j, 3)
  {
    cin >> a[i][j];
    // isCalled[A[i][j]] = true;
  }

  int n;
  cin >> n;
  rep(i, n)
  {
    int called;
    cin >> called;
    isCalled[called] = true;
  }

  bool diagLtoR = true;
  bool diagRtoL = true;

  rep(i, 3)
  {
    bool row = true;
    bool col = true;
    if (!isCalled[a[i][i]])
      diagLtoR = false;
    if (!isCalled[a[i][2 - i]])
      diagRtoL = false;
    rep(j, 3)
    {
      if (!isCalled[a[i][j]])
        row = false;
      if (!isCalled[a[j][i]])
        col = false;
    }
    if (row || col)
    {
      puts("Yes");
      return 0;
    }
  }
  if (diagLtoR || diagRtoL)
    puts("Yes");
  else
    puts("No");

  return 0;
}