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

istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint comb(int a, int b) {
  if (a < b) return 0;
  if (b < 0 || a < 0) return 0;
  mint ret = 1;
  rep(i, b) {
    ret *= (a-i);
  }
  rep(i,b) ret /= (i+1); 
  return ret;
}

mint c[4005][4005];

mint comb2(int a, int b) {
  return c[a][b];
}

mint f2(int x, int y) {
  return comb(x+y-1, y-1);
}

mint f(int x, int y) {
  if (x < y) return 0;
  if (x == y) return 1;
  if (y < 1) return 0;
  return f2(x-y, y);
}


int main() {
  int n,k; cin >> n >> k; 
  for(int i=1; i<=k; i++) {
    mint ans = f(k, i);
    mint s = 0;
    s += f(n-k, i);
    s *= 2;
    s += f(n-k, i+1);
    s += f(n-k, i-1);
    ans *= s;
    printf("%lld\n", ans.x);
  }
  
  return 0;
}