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
int main() {
  cin >> N >> M;
  vii p(M);
  rep(i, M) { cin >> p[i].fi >> p[i].se; }
  int K;
  cin >> K;
  vii b(K);
  rep(i, K) cin >> b[i].fi >> b[i].se;
  int ans = 0;
  rep(i, 1 << K) {
    vi cnt(N + 1);
    rep(j, K) {
      if ((1 << j) & i) {
        // put on c
        cnt[b[j].fi]++;
      } else {
        // put on d
        cnt[b[j].se]++;
      }
    }
    int now = 0;
    rep(j, M) {
      if (cnt[p[j].fi] > 0 && cnt[p[j].se] > 0) {
        now++;
      }
    }
    chmax(ans, now);
  }
  cout << ans << endl;
  return 0;
}
