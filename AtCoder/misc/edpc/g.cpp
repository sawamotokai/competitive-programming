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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++
vi to[100500];
int main() {
  int n, m;
  cin >> n >> m;
  vi deg(n);
  vi dp(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    deg[b]++;
  }
  queue<int> st;
  rep(i, n) if (deg[i] == 0) st.emplace(i);
  while (st.size()) {
    int v = st.front();
    st.pop();
    for (int u : to[v]) {
      deg[u]--;
      chmax(dp[u], dp[v] + 1);
      if (deg[u] == 0)
        st.emplace(u);
    }
  }
  int ans = 0;
  rep(i, n) chmax(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
