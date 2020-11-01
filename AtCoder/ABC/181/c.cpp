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

int N;
int x[105];
int y[105];
int main() {
  cin >> N;
  rep(i, N) cin >> x[i] >> y[i];
  bool ok = false;
  rep(i, N) {
    rep(j, N) {
      if (i == j)
        continue;
      rep(k, N) {
        if (i == k || j == k)
          continue;
        ll dy1 = y[j] - y[i];
        ll dx1 = x[j] - x[i];
        ll dy2 = y[k] - y[i];
        ll dx2 = x[k] - x[i];
        if (dy1 * dx2 == dy2 * dx1)
          ok = true;
      }
    }
  }
  ok();
  return 0;
}
