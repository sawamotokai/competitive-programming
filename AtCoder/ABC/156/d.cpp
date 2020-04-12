#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a; } // a <= b
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }
//clang++ -std=c++11 -stdlib=libc++ 

ll twoToThe(int n) {
  if (n==0) return 1;
  if (n&1) return (int) (2 * pow(twoToThe(n/2),2))% (int) (1e9+7);
  return (int) pow(twoToThe(n/2),2) % (int) (1e9+7);
}

const int mod = 1000000007;
// const int mod = 998244353;
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
  ll n, a, b;
  cin >> n >> a >> b;
  ll all = twoToThe(n);
  ll x,y; x = y = 1;
  ll x_denom=1, y_denom=1; 
  rep(i, a) {
    x *= n-i;
    x %= mod;
    x_denom *= (i+1);
  }
  rep(i, b) {
    y *= n-i;
    y %= mod;
    y_denom *= i+1;
  }
  x *= modinv(x_denom, mod);
  y *= modinv(y_denom, mod);
  all -= (1+x+y);
  all%=mod;
  if (all <0) all += mod;
  cout << all << endl;
  return 0;
}