#include <algorithm>
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
int a[11][11];
ii R[104];
int n, m;
int perm[11];
int used[11];
int ans = INF;
void dfs(int p = 0) {
  if (p == n) {
    int now = 0;
    rep(i, n) { now += a[perm[i]][i]; }
    chmin(ans, now);
    return;
  }
  rep(i, n) {
    if (used[i])
      continue;
    int ok = 1;
    rep(j, m) {
      if (p == 0)
        break;
      if ((R[j].fi == perm[p - 1] and R[j].se == i) or
          (R[j].se == perm[p - 1] and R[j].fi == i)) {
        ok = false;
        break;
      }
    }
    if (!ok)
      continue;
    used[i] = 1;
    perm[p] = i;
    dfs(p + 1);
    used[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  cin >> n;
  rep(i, n) {
    rep(j, n) { cin >> a[i][j]; }
  }
  cin >> m;
  rep(i, m) {
    cin >> R[i].fi >> R[i].se;
    R[i].fi--;
    R[i].se--;
  }
  dfs();
  if (ans == INF)
    ans = -1;
  cout << ans << nl;
  return 0;
}
