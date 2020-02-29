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
  int n;
  vi a;
  cin >> n;
  rep(i, n)
  {
    int num;
    cin >> num;
    a.push_back(num);
  }
  sort(a.begin(), a.end());

  ll ans = 0;
  rep(i, n) ans += a[i];
  rep(i, n)
  {
    int product = a[i] * (i + 1);
    ans += product;
  }
  ans -= a[a.size() - 1];
  cout << ans << endl;

  return 0;
}