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
int dist[505][505];
int main() {
  cin >> H >> W;
  rep(i, H) rep(j, W) dist[i][j] = INF;
  vvi grid(H, vi(W));
  rep(i, H) {
    string s;
    cin >> s;
    rep(j, W) { grid[i][j] = s[j] - '0'; }
  }
  queue<ii> q;
  dist[0][0] = 0;
  q.emplace(0, 0);
  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    int k = grid[i][j];
    rep(l, 4) {
      int ni = i + k * dy[l];
      int nj = j + k * dx[l];
      if (ni < 0 or ni >= H or nj < 0 or nj >= W)
        continue;
      if (chmin(dist[ni][nj], dist[i][j] + 1))
        q.emplace(ni, nj);
    }
  }
  int ans = dist[H - 1][W - 1];
  if (ans == INF) {
    puts("IMPOSSIBLE");
    return 0;
  }
  cout << ans << endl;
  return 0;
}
