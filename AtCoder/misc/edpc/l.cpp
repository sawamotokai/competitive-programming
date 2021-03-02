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
using vvll = vector<vll>;
// clang++ -std=c++11 -stdlib=libc++

ll dp[3005][3005][2];
ll A[3005];
ll mem(int l, int r, int player) {
  if (dp[l][r][player] != -1)
    return dp[l][r][player];
  if (l == r) {
    if (player == 0)
      return dp[l][r][player] = A[l];
    else
      return dp[l][r][player] = -A[l];
  }
  ll left = mem(l + 1, r, !player);
  ll right = mem(l, r - 1, !player);
  ll ret = 0;
  if (player == 0)
    ret = max(left + A[l], right + A[r]);
  else
    ret = min(left - A[l], right - A[r]);
  return dp[l][r][player] = ret;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> A[i];
  memset(dp, -1, sizeof(dp));
  cout << mem(0, n - 1, 0) << endl;
  return 0;
}
