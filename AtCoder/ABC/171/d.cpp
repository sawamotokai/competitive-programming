#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

vector<ll> a;

map<ll, ll> mp;
ll sum;

void solve() {
  ll b,c; cin >> b >> c;
  sum -= mp[b]*b;
  sum += mp[b]*c;
  mp[c] += mp[b]; 
  mp[b] = 0;
  printf("%lld\n", sum);
}

int main() {
  int n; cin >> n;
  a.resize(n);
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
    mp[a[i]]++;
  }
  int q; cin >> q;
  rep(i,q) solve();
  return 0;
}