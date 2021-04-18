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
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
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

void solve() {
  int n, l, r, s;
  cin >> n >> l >> r >> s;
  int w = r - l + 1;
  int mx = (2 * n - w + 1) * w / 2;
  if (mx < s) {
    cout << -1 << nl;
    return;
  }
  int now = (1 + w) * w / 2;
  vi a(w);
  rep(i, w) a[i] = i + 1;
  int ptr = w - 1;
  if (now > s) {
    cout << -1 << nl;
    return;
  }
  while (ptr >= 0 and now < s) {
    int need = min(n - w, s - now);
    a[ptr] += need;
    now += need;
    ptr--;
  }
  if (ptr < 0 and now < s) {
    cout << -1 << nl;
    return;
  }
  set<int> st;
  rep(i, w) st.insert(a[i]);
  ptr = 0;
  vi ans(n);
  int num = 1;
  rep(i, n) {
    if (i >= l - 1 and i <= r - 1) {
      ans[i] = a[ptr++];
    } else {
      while (st.count(num)) {
        num++;
      }
      ans[i] = num;
      st.insert(num);
    }
  }
  priv(ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
