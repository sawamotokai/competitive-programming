#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nl '\n'
#define endl                                                                   \
  '\n' #define all(c) begin(c), end(c) #define ok() puts(ok ? "Yes" : "No");
#define pcnt(x) __builtin_popcountll(x)
#define df(x) ll x = in();
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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using P = pair<ll, ll>;
using gt = greater<P>;
using minq = priority_queue<P, vector<P>, gt>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
template <class T> void print(const initializer_list<T> &il) {
  for (auto x : il) {
    cout << x << " ";
  }
  cout << "\n";
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  rep(i, n) cin >> a[i];
  map<int, ll> mp;
  rep(i, n) mp[a[i] % m]++;
  int ans = 0;
  rep(i, (m + 1) / 2 + 1) {
    if (i == 0) {
      if (mp[i] == 0)
        continue;
      mp[0] = 0;
      ans++;
      continue;
    }
    if (i == m - i) {
      if (mp[i] == 0)
        continue;
      mp[i] = 0;
      ans++;
      continue;
    }
    if (mp[i] > mp[m - i]) {
      if (mp[i] == 0 || mp[m - i] == 0)
        continue;
      mp[i] -= mp[m - i] + 1;
      mp[m - i] = 0;
      ans++;
    }
    if (mp[i] < mp[m - i]) {
      if (mp[i] == 0 || mp[m - i] == 0)
        continue;
      mp[m - i] -= mp[i] + 1;
      mp[i] = 0;
      ans++;
    }
    if (mp[i] == mp[m - i]) {
      if (mp[i] == 0 || mp[m - i] == 0)
        continue;
      mp[i] = 0;
      mp[m - i] = 0;
      ans++;
    }
  }
  rep(i, m) { ans += mp[i]; }
  cout << ans << nl;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
