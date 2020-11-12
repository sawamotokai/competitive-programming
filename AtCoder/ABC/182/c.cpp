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

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int sum = 0;
  vi c(3);
  rep(i, n) c[(s[i] - '0') % 3]++;
  int x = 0;
  rep(i, 3) x += c[i] * i;
  int ans = INF;
  rep(i1, 3) {
    rep(i2, 3) {
      if (c[1] < i1)
        continue;
      if (c[2] < i2)
        continue;
      if (i1 + i2 >= n)
        continue;
      int nx = x;
      nx -= i1 * 1;
      nx -= i2 * 2;
      if (nx % 3 == 0)
        chmin(ans, i1 + i2);
    }
  }
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
  return 0;
}
