#include <bits/stdc++.h>
#include <cassert>
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

int H, W;
int main() {
  cin >> H >> W;
  vector<string> grid(H);
  vector<vector<char>> ans(H, vector<char>(W));
  vector<vector<char>> verify(H, vector<char>(W));
  rep(i, H) cin >> grid[i];
  auto aroundBlack = [&](int i, int j) {
    bool all = grid[i][j] == '#';
    rep(k, 8) {
      int ni = i + dyy[k];
      int nj = j + dxx[k];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W)
        continue;
      if (grid[ni][nj] == '.')
        all = false;
    }
    return all;
  };
  rep(i, H) {
    rep(j, W) {
      if (aroundBlack(i, j))
        ans[i][j] = '#';
      else
        ans[i][j] = '.';
    }
  }

  rep(i, H) {
    rep(j, W) {
      if (ans[i][j] == '#') {
        verify[i][j] = '#';
        rep(k, 8) {
          int ni = i + dyy[k];
          int nj = j + dxx[k];
          if (ni < 0 || ni >= H || nj < 0 || nj >= W)
            continue;
          verify[ni][nj] = '#';
        }
      } else if (verify[i][j] != '#')
        verify[i][j] = '.';
    }
  }
  rep(i, H) {
    rep(j, W) {
      if (grid[i][j] != verify[i][j]) {
        puts("impossible");
        return 0;
      }
    }
  }
  puts("possible");
  rep(i, H) {
    rep(j, W) { cout << ans[i][j]; }
    cout << endl;
  }
  // rep(i, H) {
  //   rep(j, W) { cout << verify[i][j]; }
  //   cout << endl;
  // }
  return 0;
}
