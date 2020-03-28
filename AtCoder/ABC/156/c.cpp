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

int X[105];
int main()
{
  int n;
  cin >> n;
  rep(i, n) cin >> X[i];
  int ans = 1e9;
  for (int p = 1; p <= 100; p++)
  {
    int sum = 0;
    rep(i, n)
    {
      sum += pow((p - X[i]), 2);
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}