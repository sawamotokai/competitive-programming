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
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

ll r1, r2, c1, c2;
int main() {
  cin >> r1 >> c1 >> r2 >> c2;
  ll dx = c1 - c2;
  ll dy = r1 - r2;
  if (dx == 0 && dy == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (dx == dy || dx == -dy) {
    cout << 1 << endl;
    return 0;
  }
  if (abs(dx) + abs(dy) <= 3) {
    cout << 1 << endl;
    return 0;
  }
  rep2(di, -3, 3) {
    rep2(dj, -3, 3) {
      if (di + dj > 3)
        continue;
      ll ni = r2 + di;
      ll nj = c2 + dj;
      if (ni - r1 == nj - c1 || ni - r1 == c1 - nj) {
        cout << 2 << endl;
        return 0;
      }
    }
  }
  ll p = (c2 - r2) - (c1 - r1);
  if (p & 1) {
    cout << 3 << endl;
  } else {
    cout << 2 << endl;
  }
  return 0;
}
