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

int grid[10][10];
int main() {
  int x, y;
  string W;
  cin >> x >> y >> W;
  x--;
  y--;
  rep(i, 9) rep(j, 9) {
    char c;
    cin >> c;
    grid[i][j] = c - '0';
  }
  int dx, dy;
  if (W == "U")
    dx = 0, dy = -1;
  if (W == "R")
    dx = 1, dy = 0;
  if (W == "L")
    dx = -1, dy = 0;
  if (W == "D")
    dx = 0, dy = 1;
  if (W == "RU")
    dx = 1, dy = -1;
  if (W == "RD")
    dx = 1, dy = 1;
  if (W == "LU")
    dx = -1, dy = -1;
  if (W == "LD")
    dx = -1, dy = 1;
  rep(_, 4) {
    cout << grid[y][x];
    // cout << x << " " << y << endl;
    int nj = dx + x;
    int ni = dy + y;
    if (ni == -1) {
      dy = 1;
      ni = 1;
    } else if (ni == 9) {
      dy = -1;
      ni = 7;
    }
    if (nj == -1) {
      dx = 1;
      nj = 1;
    } else if (nj == 9) {
      dx = -1;
      nj = 7;
    }
    x = nj;
    y = ni;
  }
  cout << endl;
  return 0;
}
