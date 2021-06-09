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

int mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int h, w;
  cin >> h >> w;
  vs grid(h);
  rep(i, h) cin >> grid[i];
  ll ans = 1;
  rep2(k, 0, h + w - 2) {
    int now = 0;
    bool mul = 0;
    [&] {
      rep(i, h) {
        if (i > k)
          break;
        rep(j, w) {
          if (j + i > k)
            break;
          if (i + j != k)
            continue;
          assert(i + j == k);
          if (grid[i][j] == '.') {
            mul = 1;
            continue;
          }
          // R=1
          // B=2
          if (grid[i][j] == 'R') {
            if (now == 2) {
              ans = 0;
              return;
            } else
              now = 1;
          }
          if (grid[i][j] == 'B') {
            if (now == 1) {
              ans = 0;
              return;
            } else
              now = 2;
          }
        }
      }
    }();
    if (mul) {
      if (now == 0) {
        ans *= 2;
        ans %= mod;
      }
    }
  }
  cout << ans << nl;
  return 0;
}
