#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
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

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};
int main() {
  int n,k; cin >> n >> k;
  vll a(n);
  int neg = 0;
  int pos = 0;
  int zero = 0;
  rep(i,n) {
    cin >> a[i];
    if (a[i] < 0) neg++;
    if (a[i] > 0) pos++;
    if (a[i] == 0) zero++;
  }
  sort(a.begin(), a.end(), [](ll a, ll b) {return abs(a) > abs(b);});
  // rep(i,k) {
  //   if (a[i] == 0) zero++;
  // }
  // if (zero) {
  //   cout << 0 << endl; 
  //   return 0;
  // } 
  mint ans = 1;

  if ((pos == 0 && k&1)|| ((pos & 1) == 0 && pos-1 + neg < k)) {
    // ans will be neg -> greeedy from smaller abs val
    // if theres zero, zero is max
    if (zero) {
      cout << 0 << endl;
      return 0;
    }
    reverse(a.begin(), a.end());
    rep(i, k) {
      (ans *= a[i]);
    }
  } else 
   {
    // greedy from largest
    rep(i,k) {
      (ans *= a[i]);
    }
  }
  if (ans.x < 0) {
    ans += mod;
  }
  cout << ans.x << endl;
  return 0;
}