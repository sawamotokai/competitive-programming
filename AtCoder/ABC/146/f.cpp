#include <atcoder/all>
#include <bits/stdc++.h>
#include <cassert>
using namespace atcoder;
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

int N, M;
string s;
int op(int a, int b) { return min(a, b); }
int e() { return INF; };
int main() {
  cin >> N >> M >> s;
  segtree<int, op, e> seg(N + 1);
  rep(i, N + 1) seg.set(i, INF);
  seg.set(0, 0);
  rep2(i, 1, N) {
    if (s[i] == '1')
      continue;
    int left = max(0, int(i - M));
    int now = seg.prod(left, i);
    if (now == INF)
      continue;
    seg.set(i, now + 1);
  }
  if (seg.get(N) == INF) {
    cout << -1 << endl;
    return 0;
  }
  int now = seg.get(N) - 1;
  int r = N;
  int l = N;
  vi ids;
  ids.pb(N);
  vi ans;
  while (now >= 0) {
    int nx;
    rep(i, M) {
      int id = r - i - 1;
      if (id < 0)
        break;
      if (seg.get(id) == now)
        nx = id;
    }
    r = nx;
    ids.pb(nx);
    now--;
  }
  reverse(all(ids));
  rep(i, ids.size() - 1) { cout << ids[i + 1] - ids[i] << endl; }
  // rep(i, ans.size()) printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : '
  // '); rep(i, N + 1) cout << seg.get(i) << endl;
  return 0;
}
