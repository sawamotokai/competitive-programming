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

int N, M;
ll A[200006];
vi to[200005];
int indeg[200006];
ll mnCost[200005];
int main() {
  cin >> N >> M;
  rep(i, N) cin >> A[i];
  rep(i, N) mnCost[i] = LINF;

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    indeg[b]++;
  }
  queue<P> q;
  rep(i, N) {
    if (indeg[i] == 0) {
      q.emplace((ll)i, A[i]);
      // mnCost[i] = A[i];
    }
  }
  ll ans = -LINF;
  while (q.size()) {
    auto [v, boughtAt] = q.front();
    q.pop();
    for (int u : to[v]) {
      if (chmin(mnCost[u], boughtAt)) {
        q.emplace(u, min(boughtAt, A[u]));
        // cout << u << " " << mnCost[u] << endl;
      }
    }
  }
  rep(i, N) {
    chmax(ans, A[i] - mnCost[i]);
    // cout << mnCost[i] << endl;
  }
  cout << ans << endl;
  return 0;
}
