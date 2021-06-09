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
//
int dp[2005][2005];
int flag[2005][2005];
string grid[2005];

int rec(int h, int w) {
  if (flag[h][w]) {
    return dp[h][w];
  }
  flag[h][w] = 1;
  if ((h + w) & 1) {
    // aoki is moving
    if (h) {
      dp[h][w] = rec(h - 1, w);
    }
    if (w) {
      chmin(dp[h][w], rec(h, w - 1));
    }
    if (grid[h][w] == '+') {
      dp[h][w]++;
    } else {
      dp[h][w]--;
    }
  } else {
    // takahashi
    if (h) {
      dp[h][w] = rec(h - 1, w);
    }
    if (w) {
      chmax(dp[h][w], rec(h, w - 1));
    }
    if (grid[h][w] == '-') {
      dp[h][w]++;
    } else {
      dp[h][w]--;
    }
  }
  return dp[h][w];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int h, w;
  cin >> h >> w;
  rep(i, h) cin >> grid[i];
  flag[0][0] = 1;
  int res = rec(h - 1, w - 1);
  string ans;
  if (res > 0) {
    ans = "Takahashi";
  }
  if (res < 0) {
    ans = "Aoki";
  }
  if (res == 0) {
    ans = "Draw";
  }
  cout << ans << nl;
  return 0;
}
