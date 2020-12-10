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
//
// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i])
        continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i) {
        if (!f[j])
          f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      if (!res.size() || res.back() != f[x])
        res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<ii> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0)
      return {};
    vector<ii> res(1, ii(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<pair<ll, int>> factor(ll x) {
    vector<pair<ll, int>> res;
    for (int p : primes) {
      int y = 0;
      while (x % p == 0)
        x /= p, ++y;
      if (y != 0)
        res.emplace_back(p, y);
    }
    if (x != 1)
      res.emplace_back(x, 1);
    return res;
  }
};

void solve() {
  ll x;
  cin >> x;
  vector<pair<ll, int>> res;
  for (ll i = 2; i * i <= x; i++) {
    pair<ll, int> p = {i, 0};
    while (x % i == 0) {
      p.se++;
      x /= i;
    }
    if (p.se)
      res.push_back(p);
  }
  if (x != 1)
    res.emplace_back(x, 1);
  int m = 0;
  ll fac = 0;
  for (auto p : res) {
    if (chmax(m, p.se))
      fac = p.fi;
  }
  sort(all(res), [](pair<ll, int> a, pair<ll, int> b) { return a.se > b.se; });
  // for (auto p : res) {
  //   cout << p.fi << " " << p.se << endl;
  // }
  vector<ll> ans(m, 1);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].se; j++) {
      ans[j] *= res[i].fi;
    }
  }
  reverse(all(ans));
  cout << m << endl;
  for (ll num : ans)
    printf("%lld ", num);
  puts("");
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
