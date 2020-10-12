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

int H, W;
int grid[505][505];
int main() {
  cin >> H >> W;
  rep(i, H) {
    rep(j, W) {
      cin >> grid[i][j];
      grid[i][j] &= 1;
    }
  }
  queue<ii> q;
  vvi ans;
  rep(i, H) rep(j, W) if (grid[i][j] == 1) q.emplace(i, j);
  while (q.size() > 1) {
    auto [i, j] = q.front();
    q.pop();
    auto [y, x] = q.front();
    q.pop();
    if (i > y)
      swap(i, y);
    if (j > x)
      swap(j, x);
    assert(i < y || j < x);
    while (i < y) {
      vi temp(4);
      temp[0] = i + 1;
      temp[1] = j + 1;
      i++;
      temp[2] = i + 1;
      temp[3] = j + 1;
      ans.pb(temp);
    }
    while (j < x) {
      vi temp(4);
      temp[0] = i + 1;
      temp[1] = j + 1;
      j++;
      temp[2] = i + 1;
      temp[3] = j + 1;
      ans.pb(temp);
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size())
      printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
  return 0;
}
