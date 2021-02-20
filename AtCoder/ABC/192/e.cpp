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
using P = pair<ll, ll>;
using gt = greater<P>;
using minq = priority_queue<P, vector<P>, gt>;
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

int N, M, X, Y;
vector<tuple<ll, ll, ll>> to[100005];
int main() {
  cin >> N >> M >> X >> Y;
  X--;
  Y--;
  rep(i, M) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    a--;
    b--;
    to[a].emplace_back(b, t, k);
    to[b].emplace_back(a, t, k);
  }
  minq q;
  vll dp(N, LINF);
  dp[X] = 0;
  q.emplace(0, X);
  while (q.size()) {
    auto [d, v] = q.top();
    q.pop();
    if (d > dp[v])
      continue;
    for (tuple<ll, ll, ll> nx : to[v]) {
      int u = get<0>(nx);
      ll t = get<1>(nx);
      ll k = get<2>(nx);
      ll dep = (((k - d) % k) + k) % k + d;
      // (((rest - pa.se) % k) + k) % k
      // cout << "Arrived at " << d << " leave at " << dep << " " << k << endl;
      ll nd = dep + t;
      // cout << nd << " " << t << endl;
      if (chmin(dp[u], nd)) {
        q.push({nd, u});
      }
    }
  }
  ll ans = dp[Y];
  if (dp[Y] == LINF)
    ans = -1;
  cout << ans << endl;
  return 0;
}
