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
  int h, w;
  cin >> h >> w;
  int n, m;
  cin >> n >> m;
  vs grid(h, string(w, '.'));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    grid[a][b] = 'o';
  }
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    grid[a][b] = '#';
  }
  vvi grid2(h, vi(w, 0));
  // toRight
  rep(i, h) {
    int on = 0;
    rep(j, w) {
      if (grid[i][j] == '#') {
        on = 0;
      } else if (grid[i][j] == 'o') {
        on = 1;
      }
      if (on)
        grid2[i][j] = 1;
    }
    on = 0;
    rep3(j, w - 1, 0) {
      if (grid[i][j] == '#') {
        on = 0;
      } else if (grid[i][j] == 'o') {
        on = 1;
      }
      if (on)
        grid2[i][j] = on;
    }
  }
  rep(j, w) {
    int on = 0;
    rep(i, h) {
      if (grid[i][j] == '#') {
        on = 0;
      } else if (grid[i][j] == 'o') {
        on = 1;
      }
      if (on)
        grid2[i][j] = on;
    }
    on = 0;
    rep3(i, h - 1, 0) {
      if (grid[i][j] == '#') {
        on = 0;
      } else if (grid[i][j] == 'o') {
        on = 1;
      }
      if (on)
        grid2[i][j] = on;
    }
  }
  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      //     cout << grid2[i][j] << " ";
      if (grid2[i][j])
        ans++;
    }
    //    cout << nl;
  }

  cout << ans << nl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int t = 1;
  // cin >> t;
  while (t--)
    _main();
  return 0;
}
