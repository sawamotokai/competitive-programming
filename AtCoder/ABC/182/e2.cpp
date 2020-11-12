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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

int H, W, N, M;
int wall[1505][1505];
int used[1505][1505];
int processed[1505][1505][5];

vii lights;

int main() {
  cin >> H >> W >> N >> M;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    lights.eb(a, b);
  }
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    wall[a][b] = 1;
  }
  int ans = 0;
  rep(i, N) {
    auto [y, x] = lights[i];
    used[y][x] = 1;
    for (int r = x + 1; r < W; r++) {
      if (wall[y][r])
        break;
      used[y][r] = 1;
      if (processed[y][r][0])
        break;
      processed[y][r][0] = 1;
    }
    for (int l = x - 1; l >= 0; l--) {
      if (wall[y][l])
        break;
      used[y][l] = 1;
      if (processed[y][l][1])
        break;
      processed[y][l][1] = 1;
    }
    for (int u = y - 1; u >= 0; u--) {
      if (wall[u][x])
        break;
      used[u][x] = 1;
      if (processed[u][x][2])
        break;
      processed[u][x][2] = 1;
    }
    for (int d = y + 1; d < H; d++) {
      if (wall[d][x])
        break;
      used[d][x] = 1;
      if (processed[d][x][3])
        break;
      processed[d][x][3] = 1;
    }
  }
  rep(i, H) rep(j, W) if (used[i][j]) ans++;
  cout << ans << endl;
  return 0;
}
