#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll, ll>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
  };

  istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
  ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

  struct combination {
    vector<mint> fact, ifact;
    combination(int n) : fact(n + 1), ifact(n + 1) {
      assert(n < mod);
      fact[0] = 1;
      for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
      ifact[n] = fact[n].inv();
      for (int i = n; i >= 1; --i)
        ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
      if (k < 0 || k > n)
        return 0;
      return fact[n] * ifact[k] * ifact[n - k];
    }
  };
  void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi cnt(n + 1);
    rep(i, n) cnt[a[i]]++;
    sort(a.rbegin(), a.rend());
    mint ans = 1;
    rep3(i, n, 0) {
      if (cnt[i] == 0)
        continue;
      if (k == 0)
        break;
      ll sm = min(k, cnt[i]);
      k -= sm;
      // cnt[i] C min(k, cnt[i]);
      mint now = 1;
      rep(j, sm) {
        now *= cnt[i] - j;
        now /= j + 1;
      }
      ans *= now;
    }
    cout << ans.x << endl;
  }

  int t;
  int main() {
    cin >> t;
    while (t--)
      solve();
    return 0;
  }
