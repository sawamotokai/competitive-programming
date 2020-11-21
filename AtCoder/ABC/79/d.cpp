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
int grid[205][205];
int c[20][20];

int main() {
  cin >> H >> W;
  rep(i, 10) rep(j, 10) cin >> c[i][j];
  rep(i, H) {
    rep(j, W) { cin >> grid[i][j]; }
  }
  rep(k, 10) rep(i, 10) rep(j, 10) chmin(c[i][j], c[i][k] + c[k][j]);
  map<int, int> mp;
  rep(i, H) rep(j, W) mp[grid[i][j]]++;
  ll ans = 0;
  for (auto p : mp) {
    int num = p.fi;
    int cnt = p.se;
    if (num == -1)
      continue;
    if (num == 1)
      continue;
    ans += c[num][1] * cnt;
  }
  cout << ans << endl;
  return 0;
}
