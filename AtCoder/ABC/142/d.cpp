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
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int main() {
  ll a,b; cin >> a >>b;
  ll cd = gcd(a,b);
  auto factorize = [](ll n) {
    vector<pair<ll,int>> res;
    for (ll i=2; i*i<=n; i++) {
      if (n%i) continue;
      res.push_back(make_pair(i, 0));
      while (n%i==0) {
        n/=i;
        res.back().second++;
      }
    }
    if (n!=1) res.push_back(make_pair(n,1));
    return res;
  };
  int ans = factorize(cd).size(); 
  ans++;
  cout << ans << endl;
  return 0;
}