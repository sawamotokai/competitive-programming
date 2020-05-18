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
  ll a,b,c,d; cin >> a>> b>>c>>d;
  ll ans = b-a+1;
  ll LCM = lcm(c,d);
  ll c_mul = b/c - (a-1)/c;
  ll d_mul = b/d - (a-1)/d;
  ll c_d_mul = b/LCM - (a-1)/LCM;
  ans -= c_mul;
  ans -= d_mul;
  ans += c_d_mul;
  printf("%lld\n", ans);
  return 0;
}