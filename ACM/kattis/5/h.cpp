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
int vis[11][11];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vvi gn(10, vi(10));
  vs gs(10);
  rep(i, 10) rep(j, 10) {
    char c;
    cin >> c;
    gn[i][j] = c - '0';
  }
  rep(i, 10) cin >> gs[i];
  bool ok = 1;
  // check row
  rep(i, 10) {
    int cnt = 0;
    rep(j, 10) {
      if (gs[i][j] == '*')
        cnt++;
    }
    if (cnt != 2)
      ok = 0;
  }
  // columns
  rep(j, 10) {
    int cnt = 0;
    rep(i, 10) {
      if (gs[i][j] == '*')
        cnt++;
    }
    if (cnt != 2)
      ok = 0;
  }
  // adjacent
  auto adjacent = [&](int i, int j) {
    rep(k, 8) {
      int ni = i + dyy[k];
      int nj = j + dxx[k];
      if (ni < 0 or ni >= 10 or nj < 0 or nj >= 10)
        continue;
      if (gs[ni][nj] == '*')
        return 1;
    }
    return 0;
  };
  rep(i, 10) {
    rep(j, 10) {
      if (gs[i][j] == '*' and adjacent(i, j))
        ok = 0;
    }
  }
  // regions
  rep(num, 10) {
    queue<ii> q;
    [&] {
      rep(i, 10) {
        rep(j, 10) {
          if (gn[i][j] == num) {
            q.emplace(i, j);
            vis[i][j] = 1;
            return;
          }
        }
      }
    }();
    assert(q.size());
    int cnt = 0;
    while (q.size()) {
      auto [i, j] = q.front();
      if (gs[i][j] == '*')
        cnt++;
      q.pop();
      rep(k, 4) {
        int ni = i + dy[k];
        int nj = j + dx[k];
        if (ni < 0 or ni >= 10 or nj < 0 or nj >= 10 or gn[ni][nj] != num or
            vis[ni][nj])
          continue;
        q.emplace(ni, nj);
        vis[ni][nj] = 1;
      }
    }
    if (cnt != 2)
      ok = 0;
  }
  if (ok)
    cout << "valid" << nl;
  else
    cout << "invalid" << nl;
  return 0;
}
