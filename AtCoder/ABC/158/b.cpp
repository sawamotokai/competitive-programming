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
  ll n, a, b;
  cin >> n >> a >> b;
  ll sum = a + b;
  ll ans = min(n % sum, a);
  if (n > a)
  {
    ans += a * ((n / sum));
  }
  cout << ans << endl;
  return 0;
}