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

int h, w;
int main() {
  cin >> h >> w;
  vvi grid(h, vi(w));
  vvi SS1(h + 1, vi(w + 1));
  vvi SS2(h + 1, vi(w + 1));
  rep(i, h) rep(j, w) cin >> grid[i][j];
  rep(i, h) {
    rep(j, w) {
      SS1[i + 1][j + 1] += SS1[i][j + 1] + SS1[i + 1][j] - SS1[i][j];
      SS2[i + 1][j + 1] += SS2[i][j + 1] + SS2[i + 1][j] - SS2[i][j];
      if ((i + j) & 1)
        SS1[i + 1][j + 1] += grid[i][j];
      else
        SS2[i + 1][j + 1] += grid[i][j];
    }
  }
  ll ans = 0;
  rep2(i1, 1, h) rep2(i2, i1, h) rep2(j1, 1, w) rep2(j2, j1, w) {
    int n1 =
        SS1[i2][j2] - SS1[i1 - 1][j2] - SS1[i2][j1 - 1] + SS1[i1 - 1][j1 - 1];
    int n2 =
        SS2[i2][j2] - SS2[i1 - 1][j2] - SS2[i2][j1 - 1] + SS2[i1 - 1][j1 - 1];
    // cout << n1 << " " << n2 << " " << i1 << " " << i2 << " " << j1 << " " <<
    // j2 << endl;
    if (n1 == n2)
      chmax(ans, (i2 - i1 + 1) * (j2 - j1 + 1));
  }
  cout << ans << endl;
  // rep(i, h+1) {
  // rep(j, w+1) {
  // cout << SS1[i][j] << " ";
  //}
  // cout << endl;
  //}
  return 0;
}
