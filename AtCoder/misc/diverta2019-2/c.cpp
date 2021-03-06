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

int N;
int main() {
  cin >> N;
  vll pl;
  vll mi;
  rep(i, N) {
    int a;
    cin >> a;
    if (a < 0) {
      mi.pb(a);
    } else {
      pl.pb(a);
    }
  }
  if (pl.size() && mi.size()) {
    ll ans = 0;
    for (int num : pl)
      ans += num;
    for (int num : mi)
      ans -= num;
    cout << ans << endl;
    rep(i, pl.size() - 1) {
      cout << mi[0] << " " << pl[i] << endl;
      mi[0] -= pl[i];
    }
    rep(i, mi.size()) {
      cout << pl.back() << " " << mi[i] << endl;
      pl.back() -= mi[i];
    }
  } else if (pl.size()) {
    sort(all(pl));
    ll ans = -pl[0];
    assert(pl.size() == N);
    rep2(i, 1, N - 1) ans += pl[i];
    cout << ans << endl;
    rep2(i, 1, N - 2) {
      cout << pl[0] << " " << pl[i] << endl;
      pl[0] -= pl[i];
    }
    cout << pl.back() << " " << pl[0] << endl;
  } else {
    sort(all(mi));
    ll ans = mi.back();
    assert(mi.size() == N);
    rep(i, N - 1) { ans -= mi[i]; }
    cout << ans << endl;
    rep(i, N - 1) {
      cout << mi.back() << " " << mi[i] << endl;
      mi.back() -= mi[i];
    }
  }
  return 0;
}
