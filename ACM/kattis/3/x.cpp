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

int main() {
  vector<ii> p(3);
  rep(i, 3) cin >> p[i].fi >> p[i].se;
  int longest = 0;
  int id = -1;
  rep(i, 3) if (chmax(longest, max(p[i].fi, p[i].se))) id = i;
  int h = longest;
  int w = longest - min(p[id].fi, p[id].se);
  int sum = 0;
  bool ok = true;
  rep(i, 3) {
    if (i == id)
      continue;
    if (p[i].fi == w)
      sum += p[i].se;
    else if (p[i].se == w)
      sum += p[i].fi;
    else
      ok = false;
  }
  if (sum != h) {
    ok = false;
  }
  if (ok)
    puts("YES");
  else
    puts("NO");
  return 0;
}
