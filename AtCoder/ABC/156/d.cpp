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

ll mod = 1e9 + 7;

ll factorial(ll n)
{
  ll ans = 1;
  for (int i = 1; i <= n; i++)
    ans = (ans * i) % mod;
  return ans;
}

ll choose(ll a, ll b)
{
  ll ans = ((factorial(a)) / factorial(b) / factorial(a - b)) % mod;
  return ans;
}

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = 0;
  rep(i, n) ans = (ans * 2) % mod;
  ans = (ans - 1 - choose(n, a) - choose(n, b)) % mod;
  return 0;
}