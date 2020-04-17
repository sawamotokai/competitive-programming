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
ll mod = 1e9+7;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

int main() {
  int X,Y; cin>>X>>Y;
  if ((X+Y)%3 != 0) {
    cout << 0 << endl; return 0;
  }
  int n = (2*Y-X);
  int m = (2*X-Y);
  if (n%3 != 0 || m%3 != 0) {
    cout << 0 << endl; return 0;
  }
  n/=3;
  m/=3;
  if (n<0 || m<0) {
    cout << 0 << endl; return 0;
  }
  if (n<m) swap(n,m); // n is now greater
  mint ans=1;
  for (int i=0; i<m; i++) {
    ans = ans * (m+n-i);
  }
  mint denom = 1;
  rep(i, m) denom = denom * (i+1);
  ans = ans/denom;
  cout << ans.x << endl;
  return 0;
}