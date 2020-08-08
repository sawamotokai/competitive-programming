#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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

// arc34c
// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  // vector<ii> factor(int x) {
  //   vector<int> fl = factorList(x);
  //   if (fl.size() == 0) return {};
  //   vector<ii> res(1, ii(fl[0], 0));
  //   for (int p : fl) {
  //     if (res.back().first == p) {
  //       res.back().second++;
  //     } else {
  //       res.emplace_back(p, 1);
  //     }
  //   }
  //   return res;
  // }
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};
int A,B;
int main() {
  cin >> A>> B;
  Sieve sieve(A);
  map<ll,int> mp;
  for (int i=B+1; i<=A; i++) {
    vector<pair<ll,int>> fac = sieve.factor(i);
    for (auto p: fac) mp[p.first] += p.second;
  }
  ll ans = 1;
  int mod = 1e9+7;
  for (auto p: mp) {
    (ans *= (p.second +1))%=mod;
  }
  cout << ans << endl;
  return 0;
}