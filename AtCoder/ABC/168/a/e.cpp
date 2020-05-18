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

mint comb(int n, int k) {
    if (n<k) return 0;
    if (k == 0) return 0;
    mint ret =1;
    rep(i,k) {
      ret *= (n-i);
      ret /= (i+1);
    }
    return ret;
  }

istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
int main() {
  map<pll, int> inOrder;  
  map<pll, int> reverseOrder;  
  int n; cin >> n;
  rep(i,n) {
    ll a,b;
    cin >> a>>b;
    ll GCD = gcd(abs(a),abs(b));
    a/=GCD; b/=GCD;
    inOrder[{a,b}]++;
    }
    mint ans =0;
  for(auto p: inOrder) {
    ll a = p.first.first; ll b=p.first.second;
    int kazu =0;
    printf("%lld %lld\n", a, b);
    printf("%lld %lld\n", -b, a);
    printf("%lld %lld\n", b, -a);
    if (inOrder.find({-b, a}) != inOrder.end()) kazu += inOrder[{-b,a}];
    if (inOrder.find({b, -a}) != inOrder.end()) kazu += inOrder[{b,-a}];
    ans += comb(kazu, p.second);
  } 
  ans /= 2;
  mint ANS = comb(n, 2);
  ANS -= ans;
  cout << ANS.x << endl;
  return 0;
}