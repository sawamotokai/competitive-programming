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

// abc161 f
map< ll, int > prime_factor(ll n) {
  map< ll, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

vector<ll> factorize(ll n) {
  vector<ll> ret;
  stack<ll> back;
  back.push(n);
  for (ll i=2; i*i<=n; i++) {
    if (n%i == 0) {
      if (i*i == n) {
        ret.push_back(i);
        break;
      }
      ret.push_back(i);
      back.push(n/i);
    }
  }
  while (back.size()) {
    ret.push_back(back.top());
    back.pop();
  }
  return ret;
}

int main() {
  ll n; cin >> n;
  ll ans =0;
  auto n_factors = prime_factor(n-1);
  vector<ll> n_minus = factorize(n);
  ll foo = 1;
  for (auto it: n_factors) {
    foo*=(it.second + 1);
  }
  foo--;
  ans += foo;
  for (ll fac: n_minus) {
    ll n2 = n;
    while (n2 % fac == 0) n2 /= fac;
    if (n2 == 1) {
      ans++; continue;
    }
    if (n2 % fac == 1) ans++;
  } 
  cout << ans << endl;
  return 0;
}