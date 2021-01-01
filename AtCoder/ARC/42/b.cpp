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
using P = pair<double, double>;
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

int main() {
  int x, y, N;
  cin >> x >> y >> N;
  vector<P> V(N);
  rep(i, N) cin >> V[i].fi >> V[i].se;
  double ans = INF;
  rep(i, N) {
    P p1 = V[i];
    P p2 = V[(i + 1) % N];
    P unit;
    unit.fi = p2.fi - p1.fi;
    unit.se = p2.se - p1.se;
    double len = sqrt(unit.fi * unit.fi + unit.se * unit.se);
    unit.fi /= len;
    unit.se /= len;
    P vec(p1.fi - x, p1.se - y);
    double proj = abs(vec.fi * unit.fi + unit.se * vec.se);
    double vecLen = vec.fi * vec.fi + vec.se * vec.se;
    double d = sqrt(vecLen - proj * proj);
    chmin(ans, d);
  }
  printf("%.12f\n", ans);
  return 0;
}
