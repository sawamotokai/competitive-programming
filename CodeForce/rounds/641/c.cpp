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

int main() {
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  vi freq(200005, 0);
  rep(i,n) {
    map<ll,int> fac = prime_factor(a[i]);
    for (auto it: fac) {
      int num = it.first;
      rep(j, it.second) {
        freq[(int) pow(num, j+1)]++;
      }
    }
  }
  ll ans = 1;
  rep(i,freq.size()) {
    if (freq[i] >= n-1) {
      ans *= i;
      auto fac = prime_factor(i);
      assert(fac.size() == 1);
      for (auto f: fac) {
        if (pow(f.first, f.second+1) <= 200000 && freq[(int) pow(f.first, f.second+1)] >= n-1) ans /= i; 
      }
    }
  }
  cout << ans << endl;
  return 0;
}