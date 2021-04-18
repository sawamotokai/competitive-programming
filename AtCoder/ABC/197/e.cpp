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
#define endl '\n'
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
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
inline ll in() {
  ll x;
  scanf("%lld", &x);
  return x;
}
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
const ll LINF = 8e18L + 1;
const int INF = 8e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// g++ -std=c++17 -stdlib=libc++
#define _GLIBCXX_DEBUG
// This slows down the execution; even the time complexity, since it checks if
// std funcs such as lower_bound meets prereqs

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int n;
  cin >> n;
  vvll dp(n, vll(2, LINF));
  vll mn(n + 1, INF);
  vll mx(n + 1, -INF);
  set<int> st;
  rep(i, n) {
    ll x, c;
    cin >> x >> c;
    chmin(mn[c - 1], x);
    chmax(mx[c - 1], x);
    st.insert(c - 1);
  }
  rep(i, n) print({mn[i], mx[i]});
  dp[0][0] = abs(mx[0]) + abs(mx[0] - mn[0]);
  dp[0][1] = abs(mn[0]) + abs(mx[0] - mn[0]);

  for (int i : st) {
    if (mx[i] == -INF)
      continue;
    chmin(dp[i][0], dp[i - 1][1] + abs(mx[i] - mn[i]));
    chmin(dp[i][0], dp[i - 1][0] + abs(mx[i] - mn[i]));
    chmin(dp[i][1], dp[i - 1][1] + abs(mx[i] - mn[i]));
    chmin(dp[i][1], dp[i - 1][0] + abs(mx[i] - mn[i]));
  }
  ll ans = 0;
  rep(i, n) {
    if (mx[i] == -INF)
      continue;
    ans = min(dp[i][0] + abs(mn[i]), dp[i][1] + abs(mx[i]));
  }
  cout << ans << nl;
  return 0;
}
