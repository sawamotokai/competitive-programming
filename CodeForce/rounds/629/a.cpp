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
  ll a, b;
  cin >> a >> b;
  ll dif = a - b;
  if (a % b == 0)
  {
    cout << 0 << endl;
    return;
  }
  if (dif > 0)
  {
    int quatient = (a / b);
    b += (quatient * b);
  }
  cout << b - a << endl;
}

int main()
{
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}