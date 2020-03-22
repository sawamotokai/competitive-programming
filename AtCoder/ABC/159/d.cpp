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

ll A[200010];
int main()
{
  int N;
  cin >> N;
  map<ll, ll> mp;
  rep(i, N)
  {
    cin >> A[i];
    mp[A[i]]++;
  };
  ll ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    ll freq = it->second;
    if (freq > 1)
      ans += (freq * (freq - 1) / 2);
  }
  rep(k, N)
  {
    ll t = ans;
    ll freq = mp[A[k]];
    if (freq > 1)
    {
      t -= (freq) * (freq - 1) / 2;
      t += (freq - 1) * (freq - 2) / 2;
    }
    printf("%llu\n", t);
  }
  return 0;
}