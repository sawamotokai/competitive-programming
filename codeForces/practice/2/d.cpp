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
template <class T> using minq = priority_queue<T, vector<T>, greater<T>>;
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
inline void priv(vll a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
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

void _main() {
  int n;
  cin >> n;
  vs grid(n);
  rep(i, n) cin >> grid[i];
  vii ans;
  if (grid[0][1] == grid[1][0]) {
    int num = grid[0][1] - '0';
    if (grid[n - 1][n - 2] == grid[n - 2][n - 1]) {
      int num2 = grid[n - 1][n - 2] - '0';
      if (num == num2) {
        ans.emplace_back(n, n - 1);
        ans.emplace_back(n - 1, n);
      }
    } else {
      int num2 = grid[n - 1][n - 2] - '0';
      if (num2 == num) {
        ans.emplace_back(n, n - 1);
      } else {
        ans.emplace_back(n - 1, n);
      }
    }
  } else {
    int num = grid[0][1] - '0';
    int num2 = grid[1][0] - '0';
    if (grid[n - 1][n - 2] and grid[n - 2][n - 1]) {
      int num3 = grid[n - 1][n - 2] - '0';
      if (num == num3) {
        ans.emplace_back(1, 2);
      } else {
        ans.emplace_back(2, 1);
      }
    } else {
      int num3 = grid[n - 1][n - 2] - '0';
      int num4 = grid[n - 2][n - 1] - '0';
      if (num3 == num) {
        ans.emplace_back(n, n - 1);
        ans.emplace_back(2, 1);
      } else {
        ans.emplace_back(n - 1, n);
        ans.emplace_back(2, 1);
      }
    }
  }
  cout << ans.size() << nl;
  for (auto p : ans) {
    cout << p.fi << " " << p.se << nl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int t = 1;
  cin >> t;
  while (t--)
    _main();
  return 0;
}
