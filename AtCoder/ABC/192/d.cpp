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

ll M;
string X;
int n;
ll f(ll d) {
  ll dig = 1;
  ll now = 0;
  rep(i, n) {
    now += dig * (ll)(X[i] - '0');
    if (now > M)
      return -1;
    if (i != n - 1 and (long double) dig * (long double)d > M)
      return -1;
    dig *= d;
  }
  return now;
}

int main() {
  cin >> X >> M;
  reverse(all(X));
  n = X.size();
  int d = 0;
  rep(i, X.size()) { chmax(d, X[i] - '0'); }
  d++;
  ll lef = d;
  ll rig = LINF;
  rep(i, 100) {
    ll m = (lef + rig) / 2;
    if (f(m) != -1) {
      lef = m;
    } else {
      rig = m;
    }
  }
  ll hi = lef;
  rig = hi;
  lef = d;
  rep(i, 100) {
    ll m = (lef + rig) / 2;
    if (f(m) != -1) {
      rig = m;
    } else {
      lef = m;
    }
  }
  ll lo = rig;
  ll ans = hi - lo + 1;
  // cout << hi << " " << lo << endl;
  if (f(d) == -1)
    ans = 0;
  cout << ans << endl;
  return 0;
}
