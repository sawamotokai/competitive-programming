#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n; cin >> n;
  vector<pair<ll,ll>> robots(n);
  rep(i,n) {
    ll x,l; cin >> x>>l;
    robots[i] = pair<ll,ll>(x,l);
  }
  sort(robots.begin(), robots.end(), [](pair<ll,ll> a, pair<ll,ll> b) { return (a.first+a.second < b.first + b.second);});
  ll rightMost = robots[0].first + robots[0].second;
  int ans =1;

  for (int i=1; i<n; i++) {
    if (rightMost <= robots[i].first-robots[i].second) {
      rightMost = robots[i].first + robots[i].second;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}