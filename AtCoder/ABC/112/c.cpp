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
int x[101];
int y[101];
ll h[101];
int main() {
  cin >> N;
  rep(i, N) cin >> x[i] >> y[i] >> h[i];
  auto dist = [](int cx, int cy, int x, int y) {
    return abs(cx - x) + abs(cy - y);
  };
  rep(i, 101) {
    rep(j, 101) {
      ll t = 1;
      rep(k, N) if (h[k] != 0) {
        t = dist(i, j, x[k], y[k]) + h[k];
        break;
      }
      if ([&] {
            rep(k, N) {
              int d = dist(i, j, x[k], y[k]);
              if (max(t - d, 0ll) != h[k])
                return false;
            }
            return true;
          }()) {
        printf("%d %d %lld\n", i, j, t);
      }
    }
  }
  return 0;
}
