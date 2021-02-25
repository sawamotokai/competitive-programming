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

int H, W, N;
int sx, sy;
string s;
string t;

int main() {
  cin >> H >> W >> N >> sy >> sx >> s >> t;
  // R
  int now = sx;
  bool ok = false;
  rep(i, N) {
    if (s[i] == 'R')
      now++;
    if (now > W) {
      ok = true;
    }
    if (t[i] == 'L')
      now = max(1, now - 1);
  }
  // L
  now = sx;
  rep(i, N) {
    if (s[i] == 'L')
      now--;
    if (now < 1) {
      ok = true;
    }
    if (t[i] == 'R')
      now = min(W, now + 1);
  }
  now = sy;
  rep(i, N) {
    if (s[i] == 'D')
      now++;
    if (now > H) {
      ok = true;
    }
    if (t[i] == 'U')
      now = max(1, now - 1);
  }
  now = sy;
  rep(i, N) {
    if (s[i] == 'U')
      now--;
    if (now < 1) {
      ok = true;
    }
    if (t[i] == 'D')
      now = min(H, now + 1);
  }
  if (ok)
    puts("NO");
  else
    puts("YES");
  return 0;
}
