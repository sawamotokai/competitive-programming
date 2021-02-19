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

int H, W;
int main() {
  cin >> H >> W;
  ll ans = LINF;
  rep2(i, 1, H - 1) {
    vll rec(3);
    rec[0] = W * i;
    rec[1] = (W / 2 * (H - i));
    rec[2] = ((W + 2 - 1) / 2 * (H - i));
    sort(all(rec));
    chmin(ans, rec[2] - rec[0]);
  }
  rep2(i, 1, W - 1) {
    vll rec(3);
    rec[0] = H * i;
    rec[1] = (H / 2 * (W - i));
    rec[2] = ((H + 2 - 1) / 2 * (W - i));
    sort(all(rec));
    chmin(ans, rec[2] - rec[0]);
  }
  ll vert = abs(H * (W / 3) - H * ((W + 3 - 1) / 3));
  ll hori = abs(W * (H / 3) - W * ((H + 3 - 1) / 3));
  chmin(ans, vert);
  chmin(ans, hori);
  cout << ans << endl;
  return 0;
}
