#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <utility>
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
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];
  set<pair<pair<int, int>, pair<int, int>>> ans;
  // horizontal
  rep(h, H - 1) {
    bool ok = true;
    rep(i, h + 1) {
      int ni = (h - i + 1) + h;
      if (ni >= H) {
        // no overlap
        rep(w, W) {
          if (grid[i][w] != '#')
            ok = false;
        }
      } else {
        // overlap
        rep(w, W) {
          if (grid[i][w] == grid[ni][w])
            ok = false;
        }
      }
    }
    if (ok) {
      pair<pair<int, int>, pair<int, int>> now =
          make_pair(make_pair(h + 1, 1), make_pair(h + 1, W));
      ans.insert(now);
    }
  }
  // vert
  rep(w, W - 1) {
    bool ok = true;
    rep(j, w + 1) {
      int nj = (w - j + 1) + w;
      if (nj >= W) {
        // no overlap
        rep(h, H) {
          if (grid[h][j] != '#')
            ok = false;
        }
      } else {
        // overlap
        rep(h, H) {
          if (grid[h][j] == grid[h][nj])
            ok = false;
        }
      }
    }
    if (ok) {
      pair<pair<int, int>, pair<int, int>> now =
          make_pair(make_pair(1, w + 1), make_pair(H, w + 1));
      ans.insert(now);
    }
  }
  // diago
  // fold from upper left
  rep2(i, 1, min(H, W)) {
    // 0 <= w <= i
    bool ok = true;
    rep(y, i + 1) {
      rep(x, i + 1) {
        int d = i - (x + y);
        if (d > 0) {
          int nx = x + d;
          int ny = y + d;
          if (grid[y][x] == grid[ny][nx]) {
            ok = false;
            break;
          }
        }
      }
    }
    rep(y, H) {
      rep(x, W) {
        if (y > i || x > i) {
          if (grid[y][x] != '#') {
            ok = false;
            break;
          }
        }
      }
    }
    if (ok) {
      pair<pair<int, int>, pair<int, int>> now =
          make_pair(make_pair(i + 1, 1), make_pair(1, i + 1));
      ans.insert(now);
    }
  }
  // fold from upper right
  rep2(i, 1, min(H, W)) {
    // 0 <= w <= i
    bool ok = true;
    rep(y, i + 1) {
      rep3(x, W - 1, W - i) {
        int d = i - (x + y);
        if (d > 0) {
          int nx = x + d;
          int ny = y + d;
          if (grid[y][x] == grid[ny][nx]) {
            ok = false;
            break;
          }
        }
      }
    }
    rep(y, H) {
      rep(x, W) {
        if (y > i || x > i) {
          if (grid[y][x] != '#') {
            ok = false;
            break;
          }
        }
      }
    }
    if (ok) {
      pair<pair<int, int>, pair<int, int>> now =
          make_pair(make_pair(i + 1, 1), make_pair(1, i + 1));
      ans.insert(now);
    }
  }
  pair<pair<int, int>, pair<int, int>> it = *ans.begin();
  cout << it.fi.fi << " " << it.fi.se << " " << it.se.fi << " " << it.se.se
       << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
