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
void solve() {
  ll n, m;
  cin >> n >> m;
  vll a(n);
  vll b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  vll imp, reg;
  rep(i, n) {
    if (b[i] == 1)
      reg.pb(a[i]);
    else
      imp.pb(a[i]);
  }
  sort(reg.rbegin(), reg.rend());
  sort(imp.rbegin(), imp.rend());
  int len = imp.size();
  int len2 = reg.size();
  vll ss(len + 1);
  vll ss2(len2 + 1);
  rep(i, len) ss[i + 1] += ss[i] + imp[i];
  rep(i, len2) ss2[i + 1] += ss2[i] + reg[i];
  int ans = INF;
  rep(i, len + 1) {
    ll now = ss[i];
    auto it = lower_bound(all(ss2), m - now);
    if (it == ss2.end() || *it < m - now) {
      continue;
    }
    int j = it - ss2.begin();
    chmin(ans, i * 2 + j);
  }
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}

int t;
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
