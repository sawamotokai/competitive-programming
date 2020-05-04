#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok ? "Yes" : "No");
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
typedef pair<ll, ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> b(n + 1);
  ll ans = 0;
  rep(i, n + 1)
  {
    cin >> a[i];
  }
  rep(i, n) cin >> b[i];
  b[n] = 0;
  rep(i, n + 1)
  {
    ans += min(b[i], a[i]);
    if (i != n)
    {
      ll suplus = b[i] - a[i];
      if (suplus>0) {
        ans += min(a[i+1], suplus);
        a[i+1] = max(0LL, a[i+1]-suplus);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}