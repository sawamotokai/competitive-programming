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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++
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

Sieve sieve(1e5 + 5);
int SS[100005];

void solve() {
  int l, r;
  cin >> l >> r;
  ll ans = SS[r] - SS[l - 1];
  cout << ans << endl;
}

int q;
int main() {
  cin >> q;
  rep2(i, 1, 100000) {
    if (!(i & 1)) {
      SS[i] = SS[i - 1];
      continue;
    }
    if (sieve.isPrime(i) && sieve.isPrime((i + 1) / 2))
      SS[i] = SS[i - 1] + 1;
    else
      SS[i] = SS[i - 1];
  }
  while (q--)
    solve();
  return 0;
}
