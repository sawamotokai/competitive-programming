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

int main() {
  ll n,m,k; cin >> n>> m>>k;
  vector<ll> a(n), b(m);
  rep(i,n) {
    // ll x; cin >> x;
    // a.push(x);
    cin >> a[i];
  }
  rep(i,m) {
    // ll x; cin >> x;
    // b.push(x);
    cin >> b[i];
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  ll sum = 0;
  int ans = 0;
  while(a.size() || b.size()) {
    ll na=INF,nb=INF;
    if (a.size()) {
      // na = min (na, a.front());
      na = a.back();
    }
    if (b.size()) {
      // nb = min (nb, b.front());
      nb = b.back();
    }
    auto next = [&]() {
      while (sum )
    };
    ll big = min(nb, na);
    if (nb == na) {
      if (b.size() >= 2) {
        // int idx = b.size() -2;
        int idx = next();
        nb = b[idx];
      }
      if (a.size() >= 2) {
        int idx = a.size() -2;
        na = a[idx];
      }
    }
    if (nb == na) {
      int i = 1;
      int aIdx = a.size()-i;
      int bIdx = b.size()-i;
      while (a[])
    }
    if (nb < na) {
      b.pop_back();
      // b.pop();
    } else {
      // a.pop();
      a.pop_back();
    }
    if (sum+big <= k) {
      ans++;
      sum += big;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
auto get_a = [&](int i) {
  if (a.size()-1-i )
  return a[a.size()-1-i];
}

auto f = [&](int i, int j) ->int {
  if (a[i] != b[j]) {
    if (a[i] < b[j]) return f(i+1, j);
    else return f(i, j+1);
  }
  return max(f(i+1, j), f(i, j+1));
};