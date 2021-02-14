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

int n, k;
int main() {
  cin >> n >> k;
  vi T(n);
  rep(i, n) cin >> T[i];
  int ptr = 0;
  ll ans = 0;
  ll time = 0;
  vi now = T;
  while (now.size()) {
    // rep(i, now.size()) printf("%d%c", now[i], i == now.size() - 1 ? '\n' : '
    // ');
    vi nx;
    vi kay;
    int len = now.size();
    rep(i, len) {
      kay.pb(now[i]);
      if (i % k == (k - 1) || i == len - 1) {
        sort(all(kay));
        ans += time + kay[0];
        time += kay[0];
        // cout << ans << " " << time << endl;
        rep(j, kay.size() - 1) nx.pb(kay[j + 1]);
        kay = vi();
      }
    }
    now = nx;
    nx = vi();
  }
  cout << ans << endl;
  return 0;
}
